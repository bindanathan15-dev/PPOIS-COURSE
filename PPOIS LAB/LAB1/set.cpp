#include "Set.h"
#include <sstream>
#include <algorithm>
#include <cctype>

/**
 * @brief Initializes an empty subset container.
 */
Set::Set() : isSubSet(true), atom("") {}

/**
 * @brief Initializes a simple atomic element.
 * @param singleAtom The string value of the atom.
 */
Set::Set(std::string singleAtom) : isSubSet(false), atom(singleAtom) {}

/**
 * @brief Removes duplicate elements from the set.
 *
 * Compares elements using their string representations.
 */
void Set::removeDuplicates() {
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

/**
 * @brief Checks whether the set is empty.
 * @return True if the set contains no elements.
 */
bool Set::isEmpty() const {
    if (!isSubSet) return false;
    return elements.empty();
}

/**
 * @brief Calculates the number of elements in the set.
 * @return The cardinality of the set.
 */
int Set::cardinality() const {
    if (!isSubSet) return 1;
    return elements.size();
}

/**
 * @brief Adds an element to the set.
 * @param element The element to add.
 */
void Set::addElement(const Set& element) {
    if (!isSubSet) return;
    elements.push_back(element);
    removeDuplicates();
}

/**
 * @brief Removes a specific element from the set.
 * @param element The element to remove.
 */
void Set::removeElement(const Set& element) {
    if (!isSubSet) return;
    auto it = std::remove_if(elements.begin(), elements.end(), [&](const Set& e) {
        return e.toString() == element.toString();
        });
    elements.erase(it, elements.end());
}

/**
 * @brief Checks whether an element belongs to the set.
 * @param element The element to search for.
 * @return True if the element is found.
 */
bool Set::operator[](const Set& element) const {
    if (!isSubSet) return false;
    for (const auto& elem : elements) {
        if (elem.toString() == element.toString()) return true;
    }
    return false;
}

/**
 * @brief Calculates the union of two sets.
 * @param other The second set.
 * @return A new set containing all unique elements.
 */
Set Set::operator+(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
    Set result = *this;
    for (const auto& elem : other.elements) {
        result.addElement(elem);
    }
    return result;
}

/**
 * @brief Adds another set to the current set.
 * @param other The set to add.
 * @return Reference to the modified set.
 */
Set& Set::operator+=(const Set& other) {
    *this = *this + other;
    return *this;
}

/**
 * @brief Calculates the intersection of two sets.
 * @param other The second set.
 * @return A new set containing common elements.
 */
Set Set::operator*(const Set& other) const {
    if (!this->isSubSet || !other.isSubSet) return Set();
    Set result;
    for (const auto& elem : this->elements) {
        if (other[elem]) {
            result.addElement(elem);
        }
    }
    return result;
}

/**
 * @brief Intersects the current set with another set.
 * @param other The set to intersect with.
 * @return Reference to the modified set.
 */
Set& Set::operator*=(const Set& other) {
    *this = *this * other;
    return *this;
}

/**
 * @brief Calculates the difference between two sets.
 * @param other The second set.
 * @return A new set containing elements not present in the other set.
 */
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
/**
 * @brief Removes elements belonging to another set.
 * @param other The set to subtract.
 * @return Reference to the modified set.
 */
Set& Set::operator-=(const Set& other) {
    *this = *this - other;
    return *this;
}

/**
 * @brief Generates the power set.
 *
 * Uses binary bit shifting to generate all possible subsets.
 * @return A set containing all possible subsets.
 */
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

/**
 * @brief Creates a set from a string representation.
 *
 * Parses atoms and nested subsets recursively.
 * @param str The string representing the set.
 * @return The constructed set.
 */
Set Set::fromString(const std::string& str) {
    std::string s = str;

    // Remove all whitespace characters.
    s.erase(std::remove_if(s.begin(), s.end(),
        [](unsigned char c) { return std::isspace(c); }), s.end());

    if (s.empty() || s == "{}") return Set();

    // Base case: a simple atomic string.
    if (s[0] != '{') return Set(s);

    Set mainSet;
    std::string current = "";
    int openBraces = 0;

    // Scan elements inside the set boundaries.
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

/**
 * @brief Converts the set into a string representation.
 *
 * Recursively formats nested sets.
 * @return The formatted string.
 */
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
