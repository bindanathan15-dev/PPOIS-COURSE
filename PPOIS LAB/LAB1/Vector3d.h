#ifndef VECTOR3D_H
#define VECTOR3D_H

// Class representing a 3-dimensional vector for mathematical operations
class Vector3D {
private:
    double x; // Encapsulated X coordinate
    double y; // Encapsulated Y coordinate
    double z; // Encapsulated Z coordinate

public:
    // Constructors
    Vector3D(); // Default constructor initializing to (0,0,0)
    Vector3D(double val_x, double val_y, double val_z); // Parameterized constructor

    // Secure Getters for reading private coordinates
    double getx() const;
    double gety() const;
    double getz() const;

    // Geometric calculations
    double length() const; // Calculates the magnitude/norm of the vector
    double cosineWith(const Vector3D& other) const; // Computes the cosine angle between two vectors

    // Operator Overloading for Vector Arithmetic
    Vector3D operator+(const Vector3D& other) const; // Vector addition
    Vector3D& operator+=(const Vector3D& other);

    Vector3D operator-(const Vector3D& other) const; // Vector subtraction
    Vector3D& operator-=(const Vector3D& other);

    Vector3D operator*(const Vector3D& other) const; // Cross Product multiplication
    Vector3D& operator*=(const Vector3D& other);

    // Operator Overloading for Scalar Math (with double values)
    Vector3D operator*(double scalar) const; // Scalar multiplication
    Vector3D& operator*=(double scalar);

    Vector3D operator/(double scalar) const; // Scalar division
    Vector3D& operator/=(double scalar);

    // Relational Operators based on Vector length comparisons
    bool operator>(const Vector3D& other) const;
    bool operator>=(const Vector3D& other) const;
    bool operator<(const Vector3D& other) const;
    bool operator<=(const Vector3D& other) const;
};

#endif // VECTOR3D_H
