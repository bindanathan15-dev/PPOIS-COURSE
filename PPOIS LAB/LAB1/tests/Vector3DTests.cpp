#include "Vector3D.h"
#include <gtest/gtest.h>

// ==================== CONSTRUCTORS ====================

TEST(Vector3DTests, DefaultConstructor) {
    Vector3D v;

    EXPECT_DOUBLE_EQ(v.getx(), 0.0);
    EXPECT_DOUBLE_EQ(v.gety(), 0.0);
    EXPECT_DOUBLE_EQ(v.getz(), 0.0);
}

TEST(Vector3DTests, ParameterizedConstructor) {
    Vector3D v(1.0, 2.0, 3.0);

    EXPECT_DOUBLE_EQ(v.getx(), 1.0);
    EXPECT_DOUBLE_EQ(v.gety(), 2.0);
    EXPECT_DOUBLE_EQ(v.getz(), 3.0);
}

// ==================== LENGTH ====================

TEST(Vector3DTests, LengthOfZeroVector) {
    Vector3D v(0, 0, 0);

    EXPECT_DOUBLE_EQ(v.length(), 0.0);
}

TEST(Vector3DTests, LengthOfVector) {
    Vector3D v(3, 4, 0);

    EXPECT_DOUBLE_EQ(v.length(), 5.0);
}

TEST(Vector3DTests, LengthOfThreeDimensionalVector) {
    Vector3D v(2, 3, 6);

    EXPECT_DOUBLE_EQ(v.length(), 7.0);
}

TEST(Vector3DTests, LengthOfNegativeVector) {
    Vector3D v(-3, -4, 0);

    EXPECT_DOUBLE_EQ(v.length(), 5.0);
}

// ==================== ADDITION ====================

TEST(Vector3DTests, Addition) {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);

    Vector3D result = a + b;

    EXPECT_DOUBLE_EQ(result.getx(), 5);
    EXPECT_DOUBLE_EQ(result.gety(), 7);
    EXPECT_DOUBLE_EQ(result.getz(), 9);
}

TEST(Vector3DTests, AdditionWithZeroVector) {
    Vector3D a(1, 2, 3);
    Vector3D b(0, 0, 0);

    Vector3D result = a + b;

    EXPECT_DOUBLE_EQ(result.getx(), 1);
    EXPECT_DOUBLE_EQ(result.gety(), 2);
    EXPECT_DOUBLE_EQ(result.getz(), 3);
}

TEST(Vector3DTests, AdditionAssignment) {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);

    a += b;

    EXPECT_DOUBLE_EQ(a.getx(), 5);
    EXPECT_DOUBLE_EQ(a.gety(), 7);
    EXPECT_DOUBLE_EQ(a.getz(), 9);
}

TEST(Vector3DTests, AdditionAssignmentWithZero) {
    Vector3D a(1, 2, 3);
    Vector3D b(0, 0, 0);

    a += b;

    EXPECT_DOUBLE_EQ(a.getx(), 1);
    EXPECT_DOUBLE_EQ(a.gety(), 2);
    EXPECT_DOUBLE_EQ(a.getz(), 3);
}

// ==================== SUBTRACTION ====================

TEST(Vector3DTests, Subtraction) {
    Vector3D a(5, 7, 9);
    Vector3D b(1, 2, 3);

    Vector3D result = a - b;

    EXPECT_DOUBLE_EQ(result.getx(), 4);
    EXPECT_DOUBLE_EQ(result.gety(), 5);
    EXPECT_DOUBLE_EQ(result.getz(), 6);
}

TEST(Vector3DTests, SubtractionFromItself) {
    Vector3D a(1, 2, 3);

    Vector3D result = a - a;

    EXPECT_DOUBLE_EQ(result.getx(), 0);
    EXPECT_DOUBLE_EQ(result.gety(), 0);
    EXPECT_DOUBLE_EQ(result.getz(), 0);
}

TEST(Vector3DTests, SubtractionAssignment) {
    Vector3D a(5, 7, 9);
    Vector3D b(1, 2, 3);

    a -= b;

    EXPECT_DOUBLE_EQ(a.getx(), 4);
    EXPECT_DOUBLE_EQ(a.gety(), 5);
    EXPECT_DOUBLE_EQ(a.getz(), 6);
}

TEST(Vector3DTests, SubtractionAssignmentFromItself) {
    Vector3D a(1, 2, 3);

    a -= a;

    EXPECT_DOUBLE_EQ(a.getx(), 0);
    EXPECT_DOUBLE_EQ(a.gety(), 0);
    EXPECT_DOUBLE_EQ(a.getz(), 0);
}

// ==================== CROSS PRODUCT ====================

TEST(Vector3DTests, CrossProduct) {
    Vector3D a(1, 0, 0);
    Vector3D b(0, 1, 0);

    Vector3D result = a * b;

    EXPECT_DOUBLE_EQ(result.getx(), 0);
    EXPECT_DOUBLE_EQ(result.gety(), 0);
    EXPECT_DOUBLE_EQ(result.getz(), 1);
}

TEST(Vector3DTests, CrossProductReverseOrder) {
    Vector3D a(1, 0, 0);
    Vector3D b(0, 1, 0);

    Vector3D result = b * a;

    EXPECT_DOUBLE_EQ(result.getx(), 0);
    EXPECT_DOUBLE_EQ(result.gety(), 0);
    EXPECT_DOUBLE_EQ(result.getz(), -1);
}

TEST(Vector3DTests, CrossProductParallelVectors) {
    Vector3D a(1, 2, 3);
    Vector3D b(2, 4, 6);

    Vector3D result = a * b;

    EXPECT_DOUBLE_EQ(result.length(), 0.0);
}

TEST(Vector3DTests, CrossProductWithZeroVector) {
    Vector3D a(1, 2, 3);
    Vector3D b(0, 0, 0);

    Vector3D result = a * b;

    EXPECT_DOUBLE_EQ(result.length(), 0.0);
}

TEST(Vector3DTests, CrossProductAssignment) {
    Vector3D a(1, 0, 0);
    Vector3D b(0, 1, 0);

    a *= b;

    EXPECT_DOUBLE_EQ(a.getx(), 0);
    EXPECT_DOUBLE_EQ(a.gety(), 0);
    EXPECT_DOUBLE_EQ(a.getz(), 1);
}

// ==================== SCALAR MULTIPLICATION ====================
TEST(Vector3DTests, ScalarMultiplication) {
    Vector3D v(1, 2, 3);

    Vector3D result = v * 2.0;

    EXPECT_DOUBLE_EQ(result.getx(), 2);
    EXPECT_DOUBLE_EQ(result.gety(), 4);
    EXPECT_DOUBLE_EQ(result.getz(), 6);
}

TEST(Vector3DTests, ScalarMultiplicationByZero) {
    Vector3D v(1, 2, 3);

    Vector3D result = v * 0.0;

    EXPECT_DOUBLE_EQ(result.length(), 0.0);
}

TEST(Vector3DTests, ScalarMultiplicationByNegativeNumber) {
    Vector3D v(1, 2, 3);

    Vector3D result = v * -2.0;

    EXPECT_DOUBLE_EQ(result.getx(), -2);
    EXPECT_DOUBLE_EQ(result.gety(), -4);
    EXPECT_DOUBLE_EQ(result.getz(), -6);
}

TEST(Vector3DTests, ScalarMultiplicationAssignment) {
    Vector3D v(1, 2, 3);

    v *= 3.0;

    EXPECT_DOUBLE_EQ(v.getx(), 3);
    EXPECT_DOUBLE_EQ(v.gety(), 6);
    EXPECT_DOUBLE_EQ(v.getz(), 9);
}

// ==================== DIVISION ====================

TEST(Vector3DTests, ScalarDivision) {
    Vector3D v(4, 8, 12);

    Vector3D result = v / 2.0;

    EXPECT_DOUBLE_EQ(result.getx(), 2);
    EXPECT_DOUBLE_EQ(result.gety(), 4);
    EXPECT_DOUBLE_EQ(result.getz(), 6);
}

TEST(Vector3DTests, ScalarDivisionByOne) {
    Vector3D v(1, 2, 3);

    Vector3D result = v / 1.0;

    EXPECT_DOUBLE_EQ(result.getx(), 1);
    EXPECT_DOUBLE_EQ(result.gety(), 2);
    EXPECT_DOUBLE_EQ(result.getz(), 3);
}

TEST(Vector3DTests, ScalarDivisionByNegativeNumber) {
    Vector3D v(2, 4, 6);

    Vector3D result = v / -2.0;

    EXPECT_DOUBLE_EQ(result.getx(), -1);
    EXPECT_DOUBLE_EQ(result.gety(), -2);
    EXPECT_DOUBLE_EQ(result.getz(), -3);
}

TEST(Vector3DTests, ScalarDivisionAssignment) {
    Vector3D v(4, 8, 12);

    v /= 2.0;

    EXPECT_DOUBLE_EQ(v.getx(), 2);
    EXPECT_DOUBLE_EQ(v.gety(), 4);
    EXPECT_DOUBLE_EQ(v.getz(), 6);
}

// ==================== COSINE ====================

TEST(Vector3DTests, CosinePerpendicularVectors) {
    Vector3D a(1, 0, 0);
    Vector3D b(0, 1, 0);

    EXPECT_DOUBLE_EQ(a.cosineWith(b), 0.0);
}

TEST(Vector3DTests, CosineParallelVectors) {
    Vector3D a(1, 0, 0);
    Vector3D b(2, 0, 0);

    EXPECT_DOUBLE_EQ(a.cosineWith(b), 1.0);
}

TEST(Vector3DTests, CosineOppositeVectors) {
    Vector3D a(1, 0, 0);
    Vector3D b(-1, 0, 0);

    EXPECT_DOUBLE_EQ(a.cosineWith(b), -1.0);
}

TEST(Vector3DTests, CosineWithZeroVectorOnLeft) {
    Vector3D a(0, 0, 0);
    Vector3D b(1, 2, 3);

    EXPECT_DOUBLE_EQ(a.cosineWith(b), 0.0);
}

TEST(Vector3DTests, CosineWithZeroVectorOnRight) {
    Vector3D a(1, 2, 3);
    Vector3D b(0, 0, 0);

    EXPECT_DOUBLE_EQ(a.cosineWith(b), 0.0);
}

TEST(Vector3DTests, CosineBetweenIdenticalVectors) {
    Vector3D a(2, 3, 4);

    EXPECT_DOUBLE_EQ(a.cosineWith(a), 1.0);
}

// ==================== COMPARISON OPERATORS ====================

TEST(Vector3DTests, GreaterThanTrue) {
    Vector3D a(3, 4, 0);
    Vector3D b(1, 0, 0);

    EXPECT_TRUE(a > b);
}

TEST(Vector3DTests, GreaterThanFalse) {
    Vector3D a(1, 0, 0);
    Vector3D b(3, 4, 0);

    EXPECT_FALSE(a > b);
}

TEST(Vector3DTests, GreaterThanOrEqualTrue) {
    Vector3D a(3, 4, 0);
    Vector3D b(1, 0, 0);

    EXPECT_TRUE(a >= b);
}

TEST(Vector3DTests, GreaterThanOrEqualEqualLengths) {
    Vector3D a(3, 4, 0);
    Vector3D b(0, 3, 4);

    EXPECT_TRUE(a >= b);
}

TEST(Vector3DTests, GreaterThanOrEqualFalse) {
    Vector3D a(1, 0, 0);
    Vector3D b(3, 4, 0);

    EXPECT_FALSE(a >= b);
}

TEST(Vector3DTests, LessThanTrue) {
    Vector3D a(1, 0, 0);
    Vector3D b(3, 4, 0);

    EXPECT_TRUE(a < b);
}

TEST(Vector3DTests, LessThanFalse) {
    Vector3D a(3, 4, 0);
    Vector3D b(1, 0, 0);

    EXPECT_FALSE(a < b);
}

TEST(Vector3DTests, LessThanOrEqualTrue) {
    Vector3D a(1, 0, 0);
    Vector3D b(3, 4, 0);

    EXPECT_TRUE(a <= b);
}

TEST(Vector3DTests, LessThanOrEqualEqualLengths) {
    Vector3D a(3, 4, 0);
    Vector3D b(0, 3, 4);

    EXPECT_TRUE(a <= b);
}

TEST(Vector3DTests, LessThanOrEqualFalse) {
    Vector3D a(3, 4, 0);
    Vector3D b(1, 0, 0);

    EXPECT_FALSE(a <= b);
}
