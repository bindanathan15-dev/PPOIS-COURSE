#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    // Constructeurs
    Vector3D(); // Constructeur par d?faut (0,0,0)
    Vector3D(double val_x, double val_y, double val_z);

    // Getters s?curis?s
    double getx() const;
    double gety() const;
    double getz() const;

    // Calculs g?om?triques de base
    double length() const;
    double cosineWith(const Vector3D& other) const; // Op?ration 6 : Cosinus

    // Op?ration 1 : Addition (+, +=)
    Vector3D operator+(const Vector3D& other) const;
    Vector3D& operator+=(const Vector3D& other);

    // Op?ration 2 : Soustraction (-, -=)
    Vector3D operator-(const Vector3D& other) const;
    Vector3D& operator-=(const Vector3D& other);

    // Op?ration 3 : Produit vectoriel (*, *= avec un autre vecteur)
    Vector3D operator*(const Vector3D& other) const;
    Vector3D& operator*=(const Vector3D& other);

    // Op?ration 4 : Multiplication par un nombre (*, *= avec un double)
    Vector3D operator*(double scalar) const;
    Vector3D& operator*=(double scalar);

    // Op?ration 5 : Division par un nombre (/, /= avec un double)
    Vector3D operator/(double scalar) const;
    Vector3D& operator/=(double scalar);

    // Op?ration 7 : Comparaisons bas?es sur la longueur (>, >=, <, <=)
    bool operator>(const Vector3D& other) const;
    bool operator>=(const Vector3D& other) const;
    bool operator<(const Vector3D& other) const;
    bool operator<=(const Vector3D& other) const;
};

#endif