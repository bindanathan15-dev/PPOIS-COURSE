#include "Vector3D.h"
#include <cmath> // Required for std::sqrt (square root calculations)

// Default Constructor initializing components to zero
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Parameterized Constructor mapping inputs to private members
Vector3D::Vector3D(double val_x, double val_y, double val_z) : x(val_x), y(val_y), z(val_z) {}

// Secure Getters implementations
double Vector3D::getx() const { return x; }
double Vector3D::gety() const { return y; }
double Vector3D::getz() const { return z; }

// Calculates the spatial length of the vector using Pythagoras theorem
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Vector Addition Surcharge Implementation
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

// Vector Subtraction Surcharge Implementation
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}
Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

// 3D Cross Product Surcharge Implementation
Vector3D Vector3D::operator*(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}
Vector3D& Vector3D::operator*=(const Vector3D& other) {
    *this = *this * other; // Reusing the binary multiplication operator
    return *this;
}

// Scalar Multiplication Surcharge Implementation
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}
Vector3D& Vector3D::operator*=(double scalar) {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
}

// Scalar Division Surcharge Implementation
Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
}
Vector3D& Vector3D::operator/=(double scalar) {
    x /= scalar; y /= scalar; z /= scalar;
    return *this;
}

// Computes the directional angle cosine between two vectors using Dot Product formula
double Vector3D::cosineWith(const Vector3D& other) const {
    double lenProduct = this->length() * other.length();
    if (lenProduct == 0) return 0; // Anti-crash safety check for zero division

    double dotProduct = x * other.x + y * other.y + z * other.z;
    return dotProduct / lenProduct;
}

// Relational Comparison Surcharge Implementations based on Vector magnitude
bool Vector3D::operator>(const Vector3D& other) const { return this->length() > other.length(); }
bool Vector3D::operator>=(const Vector3D& other) const { return this->length() >= other.length(); }
bool Vector3D::operator<(const Vector3D& other) const { return this->length() < other.length(); }
bool Vector3D::operator<=(const Vector3D& other) const { return this->length() <= other.length(); }
