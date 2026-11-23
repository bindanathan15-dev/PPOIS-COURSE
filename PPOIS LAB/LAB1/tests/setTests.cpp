#include "Set.h"
#include <gtest/gtest.h>

// Constructors

TEST(SetTests, DefaultConstructorCreatesEmptySet) {
    Set mySet;

    EXPECT_TRUE(mySet.isEmpty());
    EXPECT_EQ(mySet.cardinality(), 0);
    EXPECT_EQ(mySet.toString(), "{}");
}

TEST(SetTests, AtomConstructor) {
    Set atom("a");

    EXPECT_FALSE(atom.isEmpty());
    EXPECT_EQ(atom.cardinality(), 1);
    EXPECT_EQ(atom.toString(), "a");
}

// Basic operations

TEST(SetTests, AddElement) {
    Set mySet;

    mySet.addElement(Set("a"));
    mySet.addElement(Set("b"));

    EXPECT_EQ(mySet.cardinality(), 2);
    EXPECT_EQ(mySet.toString(), "{a, b}");
}

TEST(SetTests, PreventDuplicates) {
    Set mySet;

    mySet.addElement(Set("a"));
    mySet.addElement(Set("a"));

    EXPECT_EQ(mySet.cardinality(), 1);
    EXPECT_EQ(mySet.toString(), "{a}");
}

TEST(SetTests, AddNestedSet) {
    Set mySet;
    Set nested = Set::fromString("{a, b}");

    mySet.addElement(nested);

    EXPECT_EQ(mySet.toString(), "{{a, b}}");
}

TEST(SetTests, AddElementToAtomDoesNothing) {
    Set atom("a");

    atom.addElement(Set("b"));

    EXPECT_EQ(atom.toString(), "a");
    EXPECT_EQ(atom.cardinality(), 1);
}

TEST(SetTests, RemoveElement) {
    Set mySet = Set::fromString("{a, b, c}");

    mySet.removeElement(Set("b"));

    EXPECT_EQ(mySet.toString(), "{a, c}");
}

TEST(SetTests, RemoveMissingElement) {
    Set mySet = Set::fromString("{a, b}");

    mySet.removeElement(Set("c"));

    EXPECT_EQ(mySet.toString(), "{a, b}");
}

TEST(SetTests, RemoveElementFromAtomDoesNothing) {
    Set atom("a");

    atom.removeElement(Set("a"));

    EXPECT_EQ(atom.toString(), "a");
}

// Membership

TEST(SetTests, MembershipReturnsTrue) {
    Set mySet = Set::fromString("{a, b, c}");

    EXPECT_TRUE(mySet[Set("b")]);
}

TEST(SetTests, MembershipReturnsFalse) {
    Set mySet = Set::fromString("{a, b}");

    EXPECT_FALSE(mySet[Set("c")]);
}

TEST(SetTests, MembershipInEmptySetReturnsFalse) {
    Set mySet;

    EXPECT_FALSE(mySet[Set("a")]);
}

TEST(SetTests, MembershipInAtomReturnsFalse) {
    Set atom("a");

    EXPECT_FALSE(atom[Set("a")]);
}

// Union

TEST(SetTests, Union) {
    Set first = Set::fromString("{a, b}");
    Set second = Set::fromString("{b, c}");

    EXPECT_EQ((first + second).toString(), "{a, b, c}");
}

TEST(SetTests, UnionWithEmptySet) {
    Set first = Set::fromString("{a, b}");
    Set second;

    EXPECT_EQ((first + second).toString(), "{a, b}");
}

TEST(SetTests, UnionWithAtomReturnsEmptySet) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    EXPECT_EQ((atom + mySet).toString(), "{}");
    EXPECT_EQ((mySet + atom).toString(), "{}");
    EXPECT_EQ((atom + atom).toString(), "{}");
}

TEST(SetTests, UnionAssignment) {
    Set first = Set::fromString("{a, b}");
    Set second = Set::fromString("{b, c}");

    first += second;

    EXPECT_EQ(first.toString(), "{a, b, c}");
}

TEST(SetTests, UnionAssignmentWithAtom) {
    Set atom("a");
    Set mySet = Set::fromString("{b}");

    atom += mySet;

    EXPECT_EQ(atom.toString(), "{}");
}

// Intersection

TEST(SetTests, Intersection) {
    Set first = Set::fromString("{a, b, c}");
    Set second = Set::fromString("{b, c, d}");

    EXPECT_EQ((first * second).toString(), "{b, c}");
}

TEST(SetTests, IntersectionWithoutCommonElements) {
    Set first = Set::fromString("{a, b}");
    Set second = Set::fromString("{c, d}");

    EXPECT_EQ((first * second).toString(), "{}");
}

TEST(SetTests, IntersectionWithAtomReturnsEmptySet) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    EXPECT_EQ((atom * mySet).toString(), "{}");
    EXPECT_EQ((mySet * atom).toString(), "{}");
}

TEST(SetTests, IntersectionAssignment) {
    Set first = Set::fromString("{a, b, c}");
    Set second = Set::fromString("{b, c}");

    first *= second;

    EXPECT_EQ(first.toString(), "{b, c}");
}

TEST(SetTests, IntersectionAssignmentWithAtom) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    atom *= mySet;

    EXPECT_EQ(atom.toString(), "{}");
}

// Difference
TEST(SetTests, Difference) {
    Set first = Set::fromString("{a, b, c}");
    Set second = Set::fromString("{b}");

    EXPECT_EQ((first - second).toString(), "{a, c}");
}

TEST(SetTests, DifferenceWithoutCommonElements) {
    Set first = Set::fromString("{a, b}");
    Set second = Set::fromString("{c, d}");

    EXPECT_EQ((first - second).toString(), "{a, b}");
}

TEST(SetTests, DifferenceWithAtomReturnsEmptySet) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    EXPECT_EQ((atom - mySet).toString(), "{}");
    EXPECT_EQ((mySet - atom).toString(), "{}");
}

TEST(SetTests, DifferenceAssignment) {
    Set first = Set::fromString("{a, b, c}");
    Set second = Set::fromString("{b}");

    first -= second;

    EXPECT_EQ(first.toString(), "{a, c}");
}

TEST(SetTests, DifferenceAssignmentWithAtom) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    atom -= mySet;

    EXPECT_EQ(atom.toString(), "{}");
}

// Power set

TEST(SetTests, PowerSetOfEmptySet) {
    Set mySet;

    EXPECT_EQ(mySet.powerSet().toString(), "{{}}");
}

TEST(SetTests, PowerSetOfOneElement) {
    Set mySet = Set::fromString("{a}");

    EXPECT_EQ(mySet.powerSet().cardinality(), 2);
    EXPECT_EQ(mySet.powerSet().toString(), "{{}, {a}}");
}

TEST(SetTests, PowerSetOfTwoElements) {
    Set mySet = Set::fromString("{a, b}");

    EXPECT_EQ(mySet.powerSet().cardinality(), 4);
    EXPECT_EQ(
        mySet.powerSet().toString(),
        "{{}, {a}, {b}, {a, b}}"
    );
}

TEST(SetTests, PowerSetOfAtomIsEmpty) {
    Set atom("a");

    EXPECT_EQ(atom.powerSet().toString(), "{}");
}

// String conversion

TEST(SetTests, FromStringEmptySet) {
    Set mySet = Set::fromString("{}");

    EXPECT_TRUE(mySet.isEmpty());
    EXPECT_EQ(mySet.toString(), "{}");
}

TEST(SetTests, FromStringEmptyInput) {
    Set mySet = Set::fromString("");

    EXPECT_TRUE(mySet.isEmpty());
}

TEST(SetTests, FromStringSingleAtom) {
    Set mySet = Set::fromString("hello");

    EXPECT_EQ(mySet.toString(), "hello");
}

TEST(SetTests, FromStringSimpleSet) {
    Set mySet = Set::fromString("{a, b, c}");

    EXPECT_EQ(mySet.toString(), "{a, b, c}");
}

TEST(SetTests, FromStringWithSpaces) {
    Set mySet = Set::fromString("{ a , b , c }");

    EXPECT_EQ(mySet.toString(), "{a, b, c}");
}

TEST(SetTests, FromStringNestedSet) {
    Set mySet = Set::fromString("{a, {b, c}, d}");

    EXPECT_EQ(mySet.toString(), "{a, {b, c}, d}");
}

TEST(SetTests, FromStringDeeplyNestedSet) {
    Set mySet = Set::fromString("{a, {b, {c}}}");

    EXPECT_EQ(mySet.toString(), "{a, {b, {c}}}");
}

// Final string representation

TEST(SetTests, ToStringEmptySet) {
    Set mySet;

    EXPECT_EQ(mySet.toString(), "{}");
}

TEST(SetTests, ToStringAtom) {
    Set atom("hello");

    EXPECT_EQ(atom.toString(), "hello");
}

TEST(SetTests, ToStringMultipleElements) {
    Set mySet = Set::fromString("{a, b, c}");

    EXPECT_EQ(mySet.toString(), "{a, b, c}");
}
