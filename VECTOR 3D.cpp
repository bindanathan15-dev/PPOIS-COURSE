#include "Vector3D.h"
#include <cmath> 

// Constructeurs
Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(double val_x, double val_y, double val_z) : x(val_x), y(val_y), z(val_z) {}

// Getters
double Vector3D::getx() const { return x; }
double Vector3D::gety() const { return y; }
double Vector3D::getz() const { return z; }

// Longueur
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Op?ration 1 : Addition
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

// Op?ration 2 : Soustraction
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}
Vector3D& Vector3D::operator-=(const Vector3D& other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

// Op?ration 3 : Produit Vectoriel (Cross Product)
Vector3D Vector3D::operator*(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}
Vector3D& Vector3D::operator*=(const Vector3D& other) {
    *this = *this * other;
    return *this;
}

// Op?ration 4 : Multiplication par un nombre
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}
Vector3D& Vector3D::operator*=(double scalar) {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
}

// Op?ration 5 : Division par un nombre
Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(x / scalar, y / scalar, z / scalar);
}
Vector3D& Vector3D::operator/=(double scalar) {
    x /= scalar; y /= scalar; z /= scalar;
    return *this;
}

// Op?ration 6 : Cosinus de l'angle entre deux vecteurs
double Vector3D::cosineWith(const Vector3D& other) const {
    double lenProduct = this->length() * other.length();
    if (lenProduct == 0) return 0; // S?curit? anti-division par z?ro
    // Produit scalaire divis? par le produit des longueurs
    double dotProduct = x * other.x + y * other.y + z * other.z;
    return dotProduct / lenProduct;
}

// Op?ration 7 : Comparaisons de longueurs
bool Vector3D::operator>(const Vector3D& other) const { return this->length() > other.length(); }
bool Vector3D::operator>=(const Vector3D& other) const { return this->length() >= other.length(); }
bool Vector3D::operator<(const Vector3D& other) const { return this->length() < other.length(); }
bool Vector3D::operator<=(const Vector3D& other) const { return this->length() <= other.length(); }