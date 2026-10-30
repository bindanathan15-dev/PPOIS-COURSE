#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

/// @brief Class representing a 3-dimensional vector for mathematical operations.
class Vector3D {
private:
    double x; ///< Encapsulated X coordinate
    double y; ///< Encapsulated Y coordinate
    double z; ///< Encapsulated Z coordinate

public:
    // Constructors and Resource Management (Rule of Three)
    Vector3D();
    Vector3D(double val_x, double val_y, double val_z);
    Vector3D(const Vector3D& other); // Copy constructor
    Vector3D& operator=(const Vector3D& other); // Copy assignment operator
    ~Vector3D() = default;

    // Secure Getters for reading private coordinates
    double getx() const;
    double gety() const;
    double getz() const;

    // Geometric calculations
    double length() const;
    double cosineWith(const Vector3D& other) const;

    // Operator Overloading for Vector Arithmetic
    Vector3D operator+(const Vector3D& other) const;
    Vector3D& operator+=(const Vector3D& other);
    Vector3D operator-(const Vector3D& other) const;
    Vector3D& operator-=(const Vector3D& other);
    Vector3D operator*(const Vector3D& other) const; // Cross Product multiplication
    Vector3D& operator*=(const Vector3D& other);

    // Operator Overloading for Scalar Math
    Vector3D operator*(double scalar) const;
    Vector3D& operator*=(double scalar);
    Vector3D operator/(double scalar) const;
    Vector3D& operator/=(double scalar);

    // Relational and Equality Operators
    bool operator>(const Vector3D& other) const;
    bool operator>=(const Vector3D& other) const;
    bool operator<(const Vector3D& other) const; // <-- PARFAITEMENT CORRIGE ICI
    bool operator<=(const Vector3D& other) const;
    bool operator==(const Vector3D& other) const; // Equality check requirement

    // Text stream operations (Reading/Writing requirement)
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector);
    friend std::istream& operator>>(std::istream& is, Vector3D& vector);
};

#endif // VECTOR3D_H