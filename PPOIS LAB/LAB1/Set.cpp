#include "Set.h"
#include <sstream>
#include <algorithm>

// Initializes as an empty subset container
Set::Set() : isSubSet(true), atom("") {}

// Initializes as a simple base atomic element
Set::Set(std::string singleAtom) : isSubSet(false), atom(singleAtom) {}

// Internal engine helper to sort and remove redundant items to ensure Cantor set integrity
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

// Checks if the set contains no elements
bool Set::isEmpty() const {
    if (!isSubSet) return false;
    return elements.empty();
}

// Returns the count of distinct items inside the container
int Set::cardinality() const {
    if (!isSubSet) return 1;
    return elements.size();
}

// Safely appends an element and triggers the duplicate cleaner
void Set::addElement(const Set& element) {
    if (!isSubSet) return; // Atoms cannot contain items
    elements.push_back(element);
    removeDuplicates();
}

// Traverses the container to remove a matching element
void Set::removeElement(const Set& element) {
    if (!isSubSet) return;
    auto it = std::remove_if(elements.begin(), elements.end(), [&](const Set& e) {
        return e.toString() == element.toString();
        });
    elements.erase(it, elements.end());
}

// Indexing Operator Surcharge: Performs an internal search to verify membership
bool Set::operator[](const Set& element) const {
    if (!isSubSet) return false;
    for (const auto& elem : elements) {
        if (elem.toString() == element.toString()) return true;
    }
    return false;
}

// Union Surcharge (+): Combines all elements from both containers
Set Set::operator+(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
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

// Intersection Surcharge (*): Retains only items present in both sets
Set Set::operator*(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
    Set result;
    for (const auto& elem : this->elements) {
        if (other[elem]) { // Reusing our overloaded bracket indexing operator
            result.addElement(elem);
        }
    }
    return result;
}
Set& Set::operator*=(const Set& other) {
    *this = *this * other;
    return *this;
}

// Difference Surcharge (-): Isolates items unique to Set 1
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

// Power Set Generator: Uses binary bitshifting (1 << N) to produce all 2^N mathematical subsets
Set Set::powerSet() const {
    if (!isSubSet) return Set();

    Set result;
    int setSize = elements.size();
    int powerSetSize = 1 << setSize;

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

// Recursive Terminal String Parser (Variant 1.4.1 requirement)
Set Set::fromString(const std::string& str) {
    std::string s = str;
    // Strip all whitespaces instantly
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    if (s.empty() || s == "{}") return Set();
    if (s[0] != '{') return Set(s); // Base case: it is a simple atomic string literal

    Set mainSet;
    std::string current = "";
    int openBraces = 0;

    // Recursive scanning token loop inside boundaries
    for (size_t i = 1; i < s.length() - 1; i++) {
        char ch = s[i];
        if (ch == '{') openBraces++;
        if (ch == '}') openBraces--;

        if (ch == ',' && openBraces == 0) {
            if (!current.empty()) {
                mainSet.addElement(Set::fromString(current)); // Recursive call step
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

// Recursively builds the string visualization for the standard terminal output window
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
