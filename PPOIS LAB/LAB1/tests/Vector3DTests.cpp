#include <gtest/gtest.h>
#include "Vector3D.h"

// Test default constructor
TEST(Vector3DTests, DefaultConstructor) {
    Vector3D v;
    EXPECT_DOUBLE_EQ(v.getx(), 0);
    EXPECT_DOUBLE_EQ(v.gety(), 0);
    EXPECT_DOUBLE_EQ(v.getz(), 0);
}

// Test parameterized constructor
TEST(Vector3DTests, ParameterizedConstructor) {
    Vector3D v(3, 4, 5);
    EXPECT_DOUBLE_EQ(v.getx(), 3);
    EXPECT_DOUBLE_EQ(v.gety(), 4);
    EXPECT_DOUBLE_EQ(v.getz(), 5);
}

// Test vector length
TEST(Vector3DTests, Length) {
    Vector3D v(3, 4, 0);
    EXPECT_DOUBLE_EQ(v.length(), 5);
}

// Test cosine between vectors
TEST(Vector3DTests, CosineWith) {
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);
    EXPECT_DOUBLE_EQ(v1.cosineWith(v2), 0);
}

// Test cosine with a zero vector
TEST(Vector3DTests, CosineWithZeroVector) {
    Vector3D v1(1, 2, 3);
    Vector3D v2;
    EXPECT_DOUBLE_EQ(v1.cosineWith(v2), 0);
}

// Test addition
TEST(Vector3DTests, Addition) {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    Vector3D result = v1 + v2;

    EXPECT_DOUBLE_EQ(result.getx(), 5);
    EXPECT_DOUBLE_EQ(result.gety(), 7);
    EXPECT_DOUBLE_EQ(result.getz(), 9);
}

// Test addition assignment
TEST(Vector3DTests, AdditionAssignment) {
    Vector3D v(1, 2, 3);
    v += Vector3D(1, 1, 1);

    EXPECT_DOUBLE_EQ(v.getx(), 2);
    EXPECT_DOUBLE_EQ(v.gety(), 3);
    EXPECT_DOUBLE_EQ(v.getz(), 4);
}

// Test subtraction
TEST(Vector3DTests, Subtraction) {
    Vector3D v1(5, 6, 7);
    Vector3D v2(1, 2, 3);
    Vector3D result = v1 - v2;

    EXPECT_DOUBLE_EQ(result.getx(), 4);
    EXPECT_DOUBLE_EQ(result.gety(), 4);
    EXPECT_DOUBLE_EQ(result.getz(), 4);
}

// Test subtraction assignment
TEST(Vector3DTests, SubtractionAssignment) {
    Vector3D v(5, 6, 7);
    v -= Vector3D(1, 2, 3);

    EXPECT_DOUBLE_EQ(v.getx(), 4);
    EXPECT_DOUBLE_EQ(v.gety(), 4);
    EXPECT_DOUBLE_EQ(v.getz(), 4);
}

// Test cross product
TEST(Vector3DTests, CrossProduct) {
    Vector3D v1(1, 0, 0);
    Vector3D v2(0, 1, 0);
    Vector3D result = v1 * v2;

    EXPECT_DOUBLE_EQ(result.getx(), 0);
    EXPECT_DOUBLE_EQ(result.gety(), 0);
    EXPECT_DOUBLE_EQ(result.getz(), 1);
}

// Test cross product assignment
TEST(Vector3DTests, CrossProductAssignment) {
    Vector3D v(1, 0, 0);
    v *= Vector3D(0, 1, 0);

    EXPECT_DOUBLE_EQ(v.getx(), 0);
    EXPECT_DOUBLE_EQ(v.gety(), 0);
    EXPECT_DOUBLE_EQ(v.getz(), 1);
}

// Test scalar multiplication
TEST(Vector3DTests, ScalarMultiplication) {
    Vector3D v(1, 2, 3);
    Vector3D result = v * 2;

    EXPECT_DOUBLE_EQ(result.getx(), 2);
    EXPECT_DOUBLE_EQ(result.gety(), 4);
    EXPECT_DOUBLE_EQ(result.getz(), 6);
}

// Test scalar multiplication assignment
TEST(Vector3DTests, ScalarMultiplicationAssignment) {
    Vector3D v(1, 2, 3);
    v *= 2;

    EXPECT_DOUBLE_EQ(v.getx(), 2);
    EXPECT_DOUBLE_EQ(v.gety(), 4);
    EXPECT_DOUBLE_EQ(v.getz(), 6);
}

// Test scalar division
TEST(Vector3DTests, ScalarDivision) {
    Vector3D v(4, 6, 8);
    Vector3D result = v / 2;

    EXPECT_DOUBLE_EQ(result.getx(), 2);
    EXPECT_DOUBLE_EQ(result.gety(), 3);
    EXPECT_DOUBLE_EQ(result.getz(), 4);
}

// Test scalar division assignment
TEST(Vector3DTests, ScalarDivisionAssignment) {
    Vector3D v(4, 6, 8);
    v /= 2;

    EXPECT_DOUBLE_EQ(v.getx(), 2);
    EXPECT_DOUBLE_EQ(v.gety(), 3);
    EXPECT_DOUBLE_EQ(v.getz(), 4);
}

// Test comparison operators
TEST(Vector3DTests, ComparisonOperators) {
    Vector3D v1(3, 4, 0);
    Vector3D v2(1, 2, 2);
    Vector3D v3(3, 4, 0);

    EXPECT_TRUE(v1 > v2);
    EXPECT_TRUE(v2 < v1);
    EXPECT_TRUE(v1 >= v3);
    EXPECT_TRUE(v1 <= v3);
}
TEST(Vector3DTests, ComparisonOperatorsFalseCases) {
    Vector3D shorter(1, 0, 0);
    Vector3D longer(2, 0, 0);

    EXPECT_FALSE(shorter > longer);
    EXPECT_FALSE(shorter >= longer);
    EXPECT_FALSE(longer < shorter);
    EXPECT_FALSE(longer <= shorter);
}

