#ifndef SET_H
#define SET_H

#include <string>
#include <vector>
#include <iostream>

// Class representing an Unordered Cantor Set that can contain atoms or nested subsets
class Set {
private:
    bool isSubSet;                 // Flag: true if this element is a subset, false if it's a simple atom
    std::string atom;              // Stores the string value if this element is a single atom (e.g., "a")
    std::vector<Set> elements;     // Recursive internal storage for nested set items

    // Internal engine function to automatically remove duplicate items
    void removeDuplicates();

public:
    // Constructors
    Set();                         // Default constructor creating an empty set: {}
    Set(std::string singleAtom);   // Parameterized constructor creating a basic atom element

    // Core operations
    bool isEmpty() const;          // Verifies if the current set is empty
    int cardinality() const;       // Determines the number of unique elements (size)
    void addElement(const Set& element);    // Securely adds an element (prevents duplicates)
    void removeElement(const Set& element); // Removes a specific element from the set

    // Overloaded bracket indexing operator for membership verification (True/False)
    bool operator[](const Set& element) const;

    // Set theory algebraic operations (Union +, Intersection *, Difference -)
    Set operator+(const Set& other) const;  // Union operation
    Set& operator+=(const Set& other);

    Set operator*(const Set& other) const;  // Intersection operation
    Set& operator*=(const Set& other);

    Set operator-(const Set& other) const;  // Difference operation
    Set& operator-=(const Set& other);

    // Advanced capabilities required by BSUIR
    Set powerSet() const;          // Generates the combinatorial Power Set (all possible subsets)
    static Set fromString(const std::string& str); // Recursive terminal string format parser

    // Formatting string output for console display
    std::string toString() const;
};
#endif // SET_H
