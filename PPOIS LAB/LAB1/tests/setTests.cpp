#include <gtest/gtest.h>
#include "Set.h"

// Test default constructor
TEST(SetTests, DefaultConstructor) {
    Set s;
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.cardinality(), 0);
    EXPECT_EQ(s.toString(), "{}");
}

// Test atom constructor
TEST(SetTests, AtomConstructor) {
    Set s("a");
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.cardinality(), 1);
    EXPECT_EQ(s.toString(), "a");
}

// Test adding an element
TEST(SetTests, AddElement) {
    Set s;
    s.addElement(Set("a"));
    EXPECT_EQ(s.cardinality(), 1);
    EXPECT_TRUE(s[Set("a")]);
}

// Test duplicate prevention
TEST(SetTests, PreventDuplicates) {
    Set s;
    s.addElement(Set("a"));
    s.addElement(Set("a"));
    EXPECT_EQ(s.cardinality(), 1);
}

// Test removing an element
TEST(SetTests, RemoveElement) {
    Set s;
    s.addElement(Set("a"));
    s.addElement(Set("b"));
    s.removeElement(Set("a"));

    EXPECT_EQ(s.cardinality(), 1);
    EXPECT_FALSE(s[Set("a")]);
    EXPECT_TRUE(s[Set("b")]);
}

// Test membership
TEST(SetTests, Membership) {
    Set s;
    s.addElement(Set("a"));

    EXPECT_TRUE(s[Set("a")]);
    EXPECT_FALSE(s[Set("b")]);
}

// Test union
TEST(SetTests, Union) {
    Set s1 = Set::fromString("{a, b}");
    Set s2 = Set::fromString("{b, c}");

    Set result = s1 + s2;

    EXPECT_EQ(result.toString(), "{a, b, c}");
}

// Test intersection
TEST(SetTests, Intersection) {
    Set s1 = Set::fromString("{a, b}");
    Set s2 = Set::fromString("{b, c}");

    Set result = s1 * s2;

    EXPECT_EQ(result.toString(), "{b}");
}

// Test difference
TEST(SetTests, Difference) {
    Set s1 = Set::fromString("{a, b}");
    Set s2 = Set::fromString("{b}");

    Set result = s1 - s2;

    EXPECT_EQ(result.toString(), "{a}");
}

// Test union assignment
TEST(SetTests, UnionAssignment) {
    Set s = Set::fromString("{a}");
    s += Set::fromString("{b}");

    EXPECT_EQ(s.toString(), "{a, b}");
}

// Test intersection assignment
TEST(SetTests, IntersectionAssignment) {
    Set s = Set::fromString("{a, b}");
    s *= Set::fromString("{b, c}");

    EXPECT_EQ(s.toString(), "{b}");
}

// Test difference assignment
TEST(SetTests, DifferenceAssignment) {
    Set s = Set::fromString("{a, b}");
    s -= Set::fromString("{b}");

    EXPECT_EQ(s.toString(), "{a}");
}

// Test power set
TEST(SetTests, PowerSet) {
    Set s = Set::fromString("{a, b}");
    Set result = s.powerSet();

    EXPECT_EQ(result.cardinality(), 4);
    EXPECT_EQ(result.toString(), "{{}, {a}, {b}, {a, b}}");
}

// Test parsing a simple set
TEST(SetTests, FromString) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_EQ(s.cardinality(), 3);
    EXPECT_EQ(s.toString(), "{a, b, c}");
}

// Test parsing nested sets
TEST(SetTests, NestedSetParsing) {
    Set s = Set::fromString("{a, {b, c}, {}}");

    EXPECT_EQ(s.cardinality(), 3);
    EXPECT_EQ(s.toString(), "{a, {b, c}, {}}");
}

// Test parsing an empty set
TEST(SetTests, EmptySetParsing) {
    Set s = Set::fromString("{}");

    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.toString(), "{}");
}

// Test whitespace handling
TEST(SetTests, WhitespaceParsing) {
    Set s = Set::fromString("{ a, b }");

    EXPECT_EQ(s.toString(), "{a, b}");
}

// Test operations with atomic elements
TEST(SetTests, OperationsWithAtoms) {
    Set a("a");
    Set b("b");

    EXPECT_EQ((a + b).toString(), "{}");
    EXPECT_EQ((a * b).toString(), "{}");
    EXPECT_EQ((a - b).toString(), "{}");
}

// Test power set of an empty set
TEST(SetTests, EmptyPowerSet) {
    Set s;
    Set result = s.powerSet();

    EXPECT_EQ(result.cardinality(), 1);
    EXPECT_EQ(result.toString(), 
      "{{}}");
}
TEST(SetTests, AddElementToAtomDoesNothing) {
    Set atom("a");

    atom.addElement(Set("b"));

    EXPECT_EQ(atom.toString(), "a");
    EXPECT_EQ(atom.cardinality(), 1);
}

TEST(SetTests, RemoveElementFromAtomDoesNothing) {
    Set atom("a");

    atom.removeElement(Set("a"));

    EXPECT_EQ(atom.toString(), "a");
}

TEST(SetTests, MembershipInAtomReturnsFalse) {
    Set atom("a");

    EXPECT_FALSE(atom[Set("a")]);
}

TEST(SetTests, PowerSetOfAtomIsEmpty) {
    Set atom("a");

    EXPECT_EQ(atom.powerSet().toString(), "{}");
}

TEST(SetTests, RemoveMissingElement) {
    Set mySet = Set::fromString("{a, b}");

    mySet.removeElement(Set("c"));

    EXPECT_EQ(mySet.toString(), "{a, b}");
}

TEST(SetTests, FromStringWithEmptyInput) {
    Set mySet = Set::fromString("");

    EXPECT_TRUE(mySet.isEmpty());
}

TEST(SetTests, FromStringWithSingleAtom) {
    Set mySet = Set::fromString("hello");

    EXPECT_EQ(mySet.toString(), "hello");
}

TEST(SetTests, FromStringWithRepeatedCommas) {
    Set mySet = Set::fromString("{a,,b}");

    EXPECT_EQ(mySet.toString(), "{a, b}");
}

TEST(SetTests, OperationsWithAtomsReturnEmptySet) {
    Set atom("a");
    Set mySet = Set::fromString("{a, b}");

    EXPECT_EQ((atom + mySet).toString(), "{}");
    EXPECT_EQ((mySet + atom).toString(), "{}");

    EXPECT_EQ((atom * mySet).toString(), "{}");
    EXPECT_EQ((mySet * atom).toString(), "{}");

    EXPECT_EQ((atom - mySet).toString(), "{}");
    EXPECT_EQ((mySet - atom).toString(), "{}");
}
