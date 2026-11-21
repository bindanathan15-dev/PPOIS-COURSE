#ifndef SET_H
#define SET_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Represents an Unordered Cantor Set.
 *
 * This class can contain simple atoms or nested subsets.
 * It supports set operations, membership checking and
 * recursive parsing from a string.
 */
class Set {
private:
    /**
     * @brief Indicates whether this element is a subset.
     *
     * True if the element is a subset, false if it is a simple atom.
     */
    bool isSubSet;

    /**
     * @brief Stores the value of a simple atom.
     */
    std::string atom;

    /**
     * @brief Stores the elements of the set.
     *
     * This vector allows the creation of nested sets.
     */
    std::vector<Set> elements;

    /**
     * @brief Removes duplicate elements from the set.
     */
    void removeDuplicates();

public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty set.
     */
    Set();

    /**
     * @brief Constructs a set from a single atom.
     * @param singleAtom The string value of the atom.
     */
    Set(std::string singleAtom);

    /**
     * @brief Checks whether the set is empty.
     * @return True if the set is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Calculates the cardinality of the set.
     * @return The number of unique elements.
     */
    int cardinality() const;

    /**
     * @brief Adds an element to the set.
     * @param element The element to add.
     */
    void addElement(const Set& element);

    /**
     * @brief Removes an element from the set.
     * @param element The element to remove.
     */
    void removeElement(const Set& element);

    /**
     * @brief Checks whether an element belongs to the set.
     * @param element The element to search for.
     * @return True if the element exists, false otherwise.
     */
    bool operator[](const Set& element) const;

    /**
     * @brief Calculates the union of two sets.
     * @param other The second set.
     * @return A new set containing all unique elements.
     */
    Set operator+(const Set& other) const;

    /**
     * @brief Adds another set to the current set.
     * @param other The set to add.
     * @return Reference to the modified set.
     */
    Set& operator+=(const Set& other);

    /**
     * @brief Calculates the intersection of two sets.
     * @param other The second set.
     * @return A new set containing common elements.
     */
    Set operator*(const Set& other) const;

    /**
     * @brief Intersects the current set with another set.
     * @param other The set to intersect with.
     * @return Reference to the modified set.
     */
    Set& operator*=(const Set& other);

    /**
     * @brief Calculates the difference between two sets.
     * @param other The set to subtract.
     * @return A new set containing elements not in the other set.
     */
    Set operator-(const Set& other) const;

    /**
     * @brief Removes elements belonging to another set.
     * @param other The set to subtract.
     * @return Reference to the modified set.
     */
    Set& operator-=(const Set& other);

    /**
     * @brief Generates the power set.
     *
     * The power set contains all possible subsets of the current set.
     * @return A set containing all subsets.
     */
    Set powerSet() const;

    /**
     * @brief Creates a set from a string representation.
     *
     * Parses atoms and nested subsets recursively.
     * @param str The string representing the set.
     * @return The constructed set.
     */
    static Set fromString(const std::string& str);

    /**
     * @brief Converts the set into a string.
     * @return The string representation of the set.
     */
    std::string toString() const;
};

#endif // SET_H
