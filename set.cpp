#include "Set.h"
#include <sstream>
#include <algorithm>

// 1. CONSTRUCTORS
Set::Set() : isSubSet(true), atom("") {}

Set::Set(std::string singleAtom) : isSubSet(false), atom(singleAtom) {}

// INTERNAL HELPER: Remove duplicates and sort to maintain strict Cantor representation
void Set::removeDuplicates() {
    if (!isSubSet) return;

    std::vector<Set> uniqueElements;
    for (const auto& elem : elements) {
        bool found = false;
        for (const auto& uElem : uniqueElements) {
            if (elem.toString() == uElem.toString()) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueElements.push_back(elem);
        }
    }
    elements = uniqueElements;
}

// 2. BASIC CAPABILITIES
bool Set::isEmpty() const {
    if (!isSubSet) return false;
    return elements.empty();
}

int Set::cardinality() const {
    if (!isSubSet) return 1;
    return elements.size();
}

void Set::addElement(const Set& element) {
    if (!isSubSet) return; // Cannot add elements to a single atom
    elements.push_back(element);
    removeDuplicates();
}

void Set::removeElement(const Set& element) {
    if (!isSubSet) return;
    auto it = std::remove_if(elements.begin(), elements.end(), [&](const Set& e) {
        return e.toString() == element.toString();
        });
    elements.erase(it, elements.end());
}

// 3. INDEXING OPERATOR [] (Belonging check)
bool Set::operator[](const Set& element) const {
    if (!isSubSet) return false;
    for (const auto& elem : elements) {
        if (elem.toString() == element.toString()) return true;
    }
    return false;
}

// 4. SET OPERATIONS
// Union (+)
Set Set::operator+(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set(); // Safe fallback
    Set result = *this;
    for (const auto& elem : other.elements) {
        result.addElement(elem);
    }
    return result;
}
Set& Set::operator+=(const Set& other) {
    *this = *this + other;
    return *this;
}

// Intersection (*)
Set Set::operator*(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
    Set result;
    for (const auto& elem : this->elements) {
        if (other[elem]) { // Using our own operator[] here!
            result.addElement(elem);
        }
    }
    return result;
}
Set& Set::operator*=(const Set& other) {
    *this = *this * other;
    return *this;
}

// Difference (-)
Set Set::operator-(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
    Set result;
    for (const auto& elem : this->elements) {
        if (!other[elem]) {
            result.addElement(elem);
        }
    }
    return result;
}
Set& Set::operator-=(const Set& other) {
    *this = *this - other;
    return *this;
}

// 5. ADVANCED BSUIR REQUIREMENTS
// Power Set Generator (All subsets)
Set Set::powerSet() const {
    if (!isSubSet) return Set();

    Set result;
    int setSize = elements.size();
    int powerSetSize = 1 << setSize; // 2^N subsets

    for (int counter = 0; counter < powerSetSize; counter++) {
        Set subset;
        for (int j = 0; j < setSize; j++) {
            if ((counter & (1 << j)) != 0) {
                subset.addElement(elements[j]);
            }
        }
        result.addElement(subset);
    }
    return result;
}

// Recursive String Parser (Task 1.4.1)
Set Set::fromString(const std::string& str) {
    std::string s = str;
    // Remove all whitespace
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

    if (s.empty() || s == "{}") return Set();
    if (s[0] != '{') return Set(s); // It's a simple atom (e.g., "a")

    Set mainSet;
    std::string current = "";
    int openBraces = 0;

    // Loop through the inside of the outer braces
    for (size_t i = 1; i < s.length() - 1; i++) {
        char ch = s[i];
        if (ch == '{') openBraces++;
        if (ch == '}') openBraces--;
        if (ch == ',' && openBraces == 0) {
            if (!current.empty()) {
                mainSet.addElement(Set::fromString(current));
                current = "";
            }
        }
        else {
            current += ch;
        }
    }
    if (!current.empty()) {
        mainSet.addElement(Set::fromString(current));
    }

    return mainSet;
}

// Text conversion representation
std::string Set::toString() const {
    if (!isSubSet) return atom;
    if (elements.empty()) return "{}";

    std::string result = "{";
    for (size_t i = 0; i < elements.size(); i++) {
        result += elements[i].toString();
        if (i < elements.size() - 1) result += ", ";
    }
    result += "}";
    return result;
}