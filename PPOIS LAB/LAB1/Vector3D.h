#ifndef VECTOR3D_H
#define VECTOR3D_H

/**
 * @brief Represents a three-dimensional vector.
 *
 * This class provides vector arithmetic, geometric calculations,
 * scalar operations and comparison operators.
 */
class Vector3D {
private:
    double x; ///< X coordinate.
    double y; ///< Y coordinate.
    double z; ///< Z coordinate.

public:
    /**
     * @brief Default constructor.
     * Initializes the vector to (0, 0, 0).
     */
    Vector3D();

    /**
     * @brief Parameterized constructor.
     * @param val_x X coordinate.
     * @param val_y Y coordinate.
     * @param val_z Z coordinate.
     */
    Vector3D(double val_x, double val_y, double val_z);

    /**
     * @brief Returns the X coordinate.
     * @return X coordinate.
     */
    double getx() const;

    /**
     * @brief Returns the Y coordinate.
     * @return Y coordinate.
     */
    double gety() const;

    /**
     * @brief Returns the Z coordinate.
     * @return Z coordinate.
     */
    double getz() const;

    /**
     * @brief Calculates the vector magnitude.
     * @return The length of the vector.
     */
    double length() const;

    /**
     * @brief Calculates the cosine of the angle between two vectors.
     * @param other The second vector.
     * @return The cosine of the angle.
     */
    double cosineWith(const Vector3D& other) const;

    /**
     * @brief Adds two vectors.
     * @param other The vector to add.
     * @return The resulting vector.
     */
    Vector3D operator+(const Vector3D& other) const;

    /**
     * @brief Adds another vector to this vector.
     * @param other The vector to add.
     * @return Reference to the modified vector.
     */
    Vector3D& operator+=(const Vector3D& other);

    /**
     * @brief Subtracts two vectors.
     * @param other The vector to subtract.
     * @return The resulting vector.
     */
    Vector3D operator-(const Vector3D& other) const;

    /**
     * @brief Subtracts another vector from this vector.
     * @param other The vector to subtract.
     * @return Reference to the modified vector.
     */
    Vector3D& operator-=(const Vector3D& other);

    /**
     * @brief Calculates the cross product of two vectors.
     * @param other The second vector.
     * @return The resulting cross product vector.
     */
    Vector3D operator*(const Vector3D& other) const;

    /**
     * @brief Assigns the cross product to this vector.
     * @param other The second vector.
     * @return Reference to the modified vector.
     */
    Vector3D& operator*=(const Vector3D& other);

    /**
     * @brief Multiplies the vector by a scalar.
     * @param scalar The scalar value.
     * @return The resulting vector.
     */
    Vector3D operator*(double scalar) const;

    /**
     * @brief Multiplies this vector by a scalar.
     * @param scalar The scalar value.
     * @return Reference to the modified vector.
     */
    Vector3D& operator*=(double scalar);

    /**
     * @brief Divides the vector by a scalar.
     * @param scalar The scalar value.
     * @return The resulting vector.
     */
    Vector3D operator/(double scalar) const;

    /**
     * @brief Divides this vector by a scalar.
     * @param scalar The scalar value.
     * @return Reference to the modified vector.
     */
    Vector3D& operator/=(double scalar);

    /**
     * @brief Checks whether this vector is longer than another.
     * @param other The vector to compare.
     * @return True if this vector is longer.
     */
    bool operator>(const Vector3D& other) const;

    /**
     * @brief Checks whether this vector is longer than or equal to another.
     * @param other The vector to compare.
     * @return True if this vector is longer or equal.
     */
    bool operator>=(const Vector3D& other) const;

    /**
     * @brief Checks whether this vector is shorter than another.
     * @param other The vector to compare.
     * @return True if this vector is shorter.
     */
    bool operator<(const Vector3D& other) const;
/**
     * @brief Checks whether this vector is shorter than or equal to another.
     * @param other The vector to compare.
     * @return True if this vector is shorter or equal.
     */
    bool operator<=(const Vector3D& other) const;
};

#endif // VECTOR3D_H
