#include "Set.h"
#include <gtest/gtest.h>

// ==================== CONSTRUCTORS ====================

TEST(SetTests, DefaultConstructor) {
    Set s;
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.cardinality(), 0);
    EXPECT_EQ(s.toString(), "{}");
}

TEST(SetTests, AtomConstructor) {
    Set s("a");
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.cardinality(), 1);
    EXPECT_EQ(s.toString(), "a");
}

TEST(SetTests, EmptySetConstructor) {
    Set s;
    EXPECT_EQ(s.toString(), "{}");
}

TEST(SetTests, AtomIsNotEmpty) {
    Set s("hello");
    EXPECT_FALSE(s.isEmpty());
}

// ==================== CARDINALITY ====================

TEST(SetTests, EmptySetCardinality) {
    Set s;
    EXPECT_EQ(s.cardinality(), 0);
}

TEST(SetTests, AtomCardinality) {
    Set s("a");
    EXPECT_EQ(s.cardinality(), 1);
}

TEST(SetTests, MultipleElementsCardinality) {
    Set s = Set::fromString("{a, b, c, d}");
    EXPECT_EQ(s.cardinality(), 4);
}

// ==================== ADD ELEMENT ====================

TEST(SetTests, AddOneElement) {
    Set s;
    s.addElement(Set("a"));

    EXPECT_EQ(s.toString(), "{a}");
}

TEST(SetTests, AddMultipleElements) {
    Set s;
    s.addElement(Set("a"));
    s.addElement(Set("b"));
    s.addElement(Set("c"));

    EXPECT_EQ(s.toString(), "{a, b, c}");
}

TEST(SetTests, AddDuplicateElement) {
    Set s;
    s.addElement(Set("a"));
    s.addElement(Set("a"));

    EXPECT_EQ(s.cardinality(), 1);
}

TEST(SetTests, AddDifferentElements) {
    Set s;
    s.addElement(Set("a"));
    s.addElement(Set("b"));
    s.addElement(Set("c"));

    EXPECT_EQ(s.cardinality(), 3);
}

TEST(SetTests, AddNestedSet) {
    Set s;
    s.addElement(Set::fromString("{a, b}"));

    EXPECT_EQ(s.toString(), "{{a, b}}");
}

TEST(SetTests, AddEmptySetAsElement) {
    Set s;
    s.addElement(Set());

    EXPECT_EQ(s.toString(), "{{}}");
}

TEST(SetTests, AddElementToAtomDoesNothing) {
    Set atom("a");
    atom.addElement(Set("b"));

    EXPECT_EQ(atom.toString(), "a");
    EXPECT_EQ(atom.cardinality(), 1);
}

// ==================== REMOVE ELEMENT ====================

TEST(SetTests, RemoveExistingElement) {
    Set s = Set::fromString("{a, b, c}");
    s.removeElement(Set("b"));

    EXPECT_EQ(s.toString(), "{a, c}");
}

TEST(SetTests, RemoveFirstElement) {
    Set s = Set::fromString("{a, b, c}");
    s.removeElement(Set("a"));

    EXPECT_EQ(s.toString(), "{b, c}");
}

TEST(SetTests, RemoveLastElement) {
    Set s = Set::fromString("{a, b, c}");
    s.removeElement(Set("c"));

    EXPECT_EQ(s.toString(), "{a, b}");
}

TEST(SetTests, RemoveOnlyElement) {
    Set s = Set::fromString("{a}");
    s.removeElement(Set("a"));

    EXPECT_TRUE(s.isEmpty());
}

TEST(SetTests, RemoveMissingElement) {
    Set s = Set::fromString("{a, b}");
    s.removeElement(Set("c"));

    EXPECT_EQ(s.toString(), "{a, b}");
}

TEST(SetTests, RemoveFromEmptySet) {
    Set s;
    s.removeElement(Set("a"));

    EXPECT_TRUE(s.isEmpty());
}

TEST(SetTests, RemoveElementFromAtomDoesNothing) {
    Set atom("a");
    atom.removeElement(Set("a"));

    EXPECT_EQ(atom.toString(), "a");
}

// ==================== MEMBERSHIP ====================

TEST(SetTests, MembershipFirstElement) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_TRUE(s[Set("a")]);
}

TEST(SetTests, MembershipMiddleElement) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_TRUE(s[Set("b")]);
}

TEST(SetTests, MembershipLastElement) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_TRUE(s[Set("c")]);
}

TEST(SetTests, MembershipMissingElement) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_FALSE(s[Set("d")]);
}

TEST(SetTests, MembershipEmptySet) {
    Set s;

    EXPECT_FALSE(s[Set("a")]);
}

TEST(SetTests, MembershipAtom) {
    Set atom("a");

    EXPECT_FALSE(atom[Set("a")]);
}

TEST(SetTests, MembershipNestedSet) {
    Set s = Set::fromString("{a, {b, c}}");

    EXPECT_TRUE(s[Set::fromString("{b, c}")]);
}

// ==================== UNION ====================

TEST(SetTests, Union) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{b, c}");
EXPECT_EQ((a + b).toString(), "{a, b, c}");
}

TEST(SetTests, UnionWithEmptyRightSet) {
    Set a = Set::fromString("{a, b}");
    Set b;

    EXPECT_EQ((a + b).toString(), "{a, b}");
}

TEST(SetTests, UnionWithEmptyLeftSet) {
    Set a;
    Set b = Set::fromString("{a, b}");

    EXPECT_EQ((a + b).toString(), "{a, b}");
}

TEST(SetTests, UnionTwoEmptySets) {
    Set a;
    Set b;

    EXPECT_EQ((a + b).toString(), "{}");
}

TEST(SetTests, UnionWithoutDuplicates) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{c, d}");

    EXPECT_EQ((a + b).toString(), "{a, b, c, d}");
}

TEST(SetTests, UnionWithAtomOnLeft) {
    Set a("a");
    Set b = Set::fromString("{b}");

    EXPECT_EQ((a + b).toString(), "{}");
}

TEST(SetTests, UnionWithAtomOnRight) {
    Set a = Set::fromString("{a}");
    Set b("b");

    EXPECT_EQ((a + b).toString(), "{}");
}

TEST(SetTests, UnionTwoAtoms) {
    Set a("a");
    Set b("b");

    EXPECT_EQ((a + b).toString(), "{}");
}

TEST(SetTests, UnionAssignment) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{b, c}");

    a += b;

    EXPECT_EQ(a.toString(), "{a, b, c}");
}

TEST(SetTests, UnionAssignmentWithAtom) {
    Set a("a");
    Set b = Set::fromString("{b}");

    a += b;

    EXPECT_EQ(a.toString(), "{}");
}

// ==================== INTERSECTION ====================

TEST(SetTests, Intersection) {
    Set a = Set::fromString("{a, b, c}");
    Set b = Set::fromString("{b, c, d}");

    EXPECT_EQ((a * b).toString(), "{b, c}");
}

TEST(SetTests, IntersectionOneCommonElement) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{b, c}");

    EXPECT_EQ((a * b).toString(), "{b}");
}

TEST(SetTests, IntersectionNoCommonElements) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{c, d}");

    EXPECT_EQ((a * b).toString(), "{}");
}

TEST(SetTests, IntersectionWithEmptySet) {
    Set a = Set::fromString("{a, b}");
    Set b;

    EXPECT_EQ((a * b).toString(), "{}");
}

TEST(SetTests, IntersectionTwoEmptySets) {
    Set a;
    Set b;

    EXPECT_EQ((a * b).toString(), "{}");
}

TEST(SetTests, IntersectionAtomOnLeft) {
    Set a("a");
    Set b = Set::fromString("{a}");

    EXPECT_EQ((a * b).toString(), "{}");
}

TEST(SetTests, IntersectionAtomOnRight) {
    Set a = Set::fromString("{a}");
    Set b("b");

    EXPECT_EQ((a * b).toString(), "{}");
}

TEST(SetTests, IntersectionAssignment) {
    Set a = Set::fromString("{a, b, c}");
    Set b = Set::fromString("{b, c}");

    a *= b;

    EXPECT_EQ(a.toString(), "{b, c}");
}

TEST(SetTests, IntersectionAssignmentWithAtom) {
    Set a("a");
    Set b = Set::fromString("{a}");

    a *= b;

    EXPECT_EQ(a.toString(), "{}");
}

// ==================== DIFFERENCE ====================

TEST(SetTests, Difference) {
    Set a = Set::fromString("{a, b, c}");
    Set b = Set::fromString("{b}");

    EXPECT_EQ((a - b).toString(), "{a, c}");
}

TEST(SetTests, DifferenceWithoutCommonElements) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{c, d}");

    EXPECT_EQ((a - b).toString(), "{a, b}");
}

TEST(SetTests, DifferenceAllElementsRemoved) {
    Set a = Set::fromString("{a, b}");
    Set b = Set::fromString("{a, b}");

    EXPECT_EQ((a - b).toString(), "{}");
}

TEST(SetTests, DifferenceWithEmptyRightSet) {
    Set a = Set::fromString("{a, b}");
    Set b;

    EXPECT_EQ((a - b).toString(), "{a, b}");
}

TEST(SetTests, DifferenceWithEmptyLeftSet) {
    Set a;
    Set b = Set::fromString("{a, b}");

    EXPECT_EQ((a - b).toString(), "{}");
}

TEST(SetTests, DifferenceAtomOnLeft) {
    Set a("a");
    Set b = Set::fromString("{b}");

    EXPECT_EQ((a - b).toString(), "{}");
}

TEST(SetTests, DifferenceAtomOnRight) {
    Set a = Set::fromString("{a}");
    Set b("b");

    EXPECT_EQ((a - b).toString(), "{}");
}

TEST(SetTests, DifferenceAssignment) {
    Set a = Set::fromString("{a, b, c}");
    Set b = Set::fromString("{b}");

    a -= b;

    EXPECT_EQ(a.toString(), "{a, c}");
}
TEST(SetTests, DifferenceAssignmentWithAtom) {
    Set a("a");
    Set b = Set::fromString("{b}");

    a -= b;

    EXPECT_EQ(a.toString(), "{}");
}

// ==================== POWER SET ====================

TEST(SetTests, PowerSetOfEmptySet) {
    Set s;

    EXPECT_EQ(s.powerSet().toString(), "{{}}");
}

TEST(SetTests, PowerSetOfOneElement) {
    Set s = Set::fromString("{a}");

    EXPECT_EQ(s.powerSet().cardinality(), 2);
    EXPECT_EQ(s.powerSet().toString(), "{{}, {a}}");
}

TEST(SetTests, PowerSetOfTwoElements) {
    Set s = Set::fromString("{a, b}");

    EXPECT_EQ(s.powerSet().cardinality(), 4);
    EXPECT_EQ(s.powerSet().toString(),
              "{{}, {a}, {b}, {a, b}}");
}

TEST(SetTests, PowerSetOfThreeElements) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_EQ(s.powerSet().cardinality(), 8);
}

TEST(SetTests, PowerSetOfAtom) {
    Set atom("a");

    EXPECT_EQ(atom.powerSet().toString(), "{}");
}

// ==================== FROM STRING ====================

TEST(SetTests, FromStringEmptyInput) {
    Set s = Set::fromString("");

    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.toString(), "{}");
}

TEST(SetTests, FromStringEmptySet) {
    Set s = Set::fromString("{}");

    EXPECT_TRUE(s.isEmpty());
}

TEST(SetTests, FromStringAtom) {
    Set s = Set::fromString("hello");

    EXPECT_EQ(s.toString(), "hello");
}

TEST(SetTests, FromStringSingleElement) {
    Set s = Set::fromString("{a}");

    EXPECT_EQ(s.toString(), "{a}");
}

TEST(SetTests, FromStringMultipleElements) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_EQ(s.toString(), "{a, b, c}");
}

TEST(SetTests, FromStringWithSpaces) {
    Set s = Set::fromString("{ a , b , c }");

    EXPECT_EQ(s.toString(), "{a, b, c}");
}

TEST(SetTests, FromStringWithTabsAndNewlines) {
    Set s = Set::fromString("{a,\n b,\t c}");

    EXPECT_EQ(s.toString(), "{a, b, c}");
}

TEST(SetTests, FromStringNestedSet) {
    Set s = Set::fromString("{a, {b, c}, d}");

    EXPECT_EQ(s.toString(), "{a, {b, c}, d}");
}

TEST(SetTests, FromStringDeeplyNestedSet) {
    Set s = Set::fromString("{a, {b, {c}}}");

    EXPECT_EQ(s.toString(), "{a, {b, {c}}}");
}

TEST(SetTests, FromStringNestedElementsWithCommas) {
    Set s = Set::fromString("{{a, b}, {c, d}}");

    EXPECT_EQ(s.toString(), "{{a, b}, {c, d}}");
}

TEST(SetTests, FromStringDuplicateElements) {
    Set s = Set::fromString("{a, a, b}");

    EXPECT_EQ(s.toString(), "{a, b}");
}

TEST(SetTests, FromStringEmptyNestedSet) {
    Set s = Set::fromString("{a, {}, b}");

    EXPECT_EQ(s.toString(), "{a, {}, b}");
}

// ==================== TO STRING ====================

TEST(SetTests, ToStringEmpty) {
    Set s;

    EXPECT_EQ(s.toString(), "{}");
}

TEST(SetTests, ToStringAtom) {
    Set s("hello");

    EXPECT_EQ(s.toString(), "hello");
}

TEST(SetTests, ToStringSingleElement) {
    Set s = Set::fromString("{a}");

    EXPECT_EQ(s.toString(), "{a}");
}

TEST(SetTests, ToStringMultipleElements) {
    Set s = Set::fromString("{a, b, c}");

    EXPECT_EQ(s.toString(), "{a, b, c}");
}

TEST(SetTests, ToStringNestedSet) {
    Set s = Set::fromString("{a, {b, c}}");

    EXPECT_EQ(s.toString(), "{a, {b, c}}");
}
// Your existing tests above

TEST(SetTests, RemoveDuplicatesWithDifferentElements) {
    Set set;

    set.addElement(Set("a"));
    set.addElement(Set("b"));
    set.addElement(Set("c"));

    EXPECT_EQ(set.cardinality(), 3);
    EXPECT_EQ(set.toString(), "{a, b, c}");
}

TEST(SetTests, RemoveDuplicatesWithRepeatedElements) {
    Set set;

    set.addElement(Set("a"));
    set.addElement(Set("b"));
    set.addElement(Set("a"));
    set.addElement(Set("c"));
    set.addElement(Set("b"));

    EXPECT_EQ(set.cardinality(), 3);
    EXPECT_EQ(set.toString(), "{a, b, c}");
}

TEST(SetTests, RemoveDuplicatesWithNestedSets) {
    Set set;

    set.addElement(Set::fromString("{a, b}"));
    set.addElement(Set::fromString("{c, d}"));
    set.addElement(Set::fromString("{a, b}"));

    EXPECT_EQ(set.cardinality(), 2);
}
