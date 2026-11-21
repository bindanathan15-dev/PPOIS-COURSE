#include "Vector3D.h"
#include <cmath>

/**
 * @brief Creates a vector initialized to (0, 0, 0).
 */
Vector3D::Vector3D() : x(0), y(0), z(0) {}

/**
 * @brief Creates a vector with the specified coordinates.
 * @param val_x The X coordinate.
 * @param val_y The Y coordinate.
 * @param val_z The Z coordinate.
 */
Vector3D::Vector3D(double val_x, double val_y, double val_z)
    : x(val_x), y(val_y), z(val_z) {}

/**
 * @brief Returns the X coordinate.
 * @return The X coordinate.
 */
double Vector3D::getx() const { return x; }

/**
 * @brief Returns the Y coordinate.
 * @return The Y coordinate.
 */
double Vector3D::gety() const { return y; }

/**
 * @brief Returns the Z coordinate.
 * @return The Z coordinate.
 */
double Vector3D::getz() const { return z; }

/**
 * @brief Calculates the length of the vector.
 * @return The magnitude of the vector.
 */
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

/**
 * @brief Adds another vector to the current vector.
 * @param other The second vector.
 * @return A new vector containing the sum.
 */
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

/**
 * @brief Adds another vector to the current vector.
 * @param other The second vector.
 * @return Reference to the modified vector.
 */
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

/**
 * @brief Subtracts another vector from the current vector.
 * @param other The second vector.
 * @return A new vector containing the difference.
 */
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

/**
 * @brief Subtracts another vector from the current vector.
 * @param other The second vector.
 * @return Reference to the modified vector.
 */
Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

/**
 * @brief Calculates the cross product of two vectors.
 * @param other The second vector.
 * @return A new vector representing the cross product.
 */
Vector3D Vector3D::operator*(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

/**
 * @brief Assigns the cross product to the current vector.
 * @param other The second vector.
 * @return Reference to the modified vector.
 */
Vector3D& Vector3D::operator*=(const Vector3D& other) {
    *this = *this * other;
    return *this;
}

/**
 * @brief Multiplies the vector by a scalar.
 * @param scalar The scalar value.
 * @return A new multiplied vector.
 */
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

/**
 * @brief Multiplies the current vector by a scalar.
 * @param scalar The scalar value.
 * @return Reference to the modified vector.
 */
Vector3D& Vector3D::operator*=(double scalar) {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
}

/**
 * @brief Divides the vector by a scalar.
 * @param scalar The divisor.
 * @return A new divided vector.
 */
Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

/**
 * @brief Divides the current vector by a scalar.
 * @param scalar The divisor.
 * @return Reference to the modified vector.
 */
Vector3D& Vector3D::operator/=(double scalar) {
    x /= scalar; y /= scalar; z /= scalar;
    return *this;
}

/**
 * @brief Calculates the cosine of the angle between two vectors.
 * @param other The second vector.
 * @return The cosine of the angle, or 0 if either vector has zero length.
 */
double Vector3D::cosineWith(const Vector3D& other) const {
    double lenProduct = this->length() * other.length();
    if (lenProduct == 0) return 0;

    double dotProduct = x * other.x + y * other.y + z * other.z;
    return dotProduct / lenProduct;
}
/**
 * @brief Checks whether this vector is longer than another vector.
 * @param other The second vector.
 * @return True if this vector is longer.
 */
bool Vector3D::operator>(const Vector3D& other) const {
    return this->length() > other.length();
}

/**
 * @brief Checks whether this vector is longer than or equal to another.
 * @param other The second vector.
 * @return True if this vector is longer than or equal to the other.
 */
bool Vector3D::operator>=(const Vector3D& other) const {
    return this->length() >= other.length();
}

/**
 * @brief Checks whether this vector is shorter than another vector.
 * @param other The second vector.
 * @return True if this vector is shorter.
 */
bool Vector3D::operator<(const Vector3D& other) const {
    return this->length() < other.length();
}

/**
 * @brief Checks whether this vector is shorter than or equal to another.
 * @param other The second vector.
 * @return True if this vector is shorter than or equal to the other.
 */
bool Vector3D::operator<=(const Vector3D& other) const {
    return this->length() <= other.length();
}
