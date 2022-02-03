#ifndef Quaternion3D_imp_cpp
#define Quaternion3D_imp_cpp

#include "def.h"

#include "../Vector3D/def.h"

#include <math.h>

//Constructor
Quaternion3D::Quaternion3D () {
    c = 1;
    i = 0;
    j = 0;
    k = 0;
}
Quaternion3D::Quaternion3D (float _c, float _i, float _j, float _k) {
    c = _c;
    i = _i;
    j = _j;
    k = _k;
}
Quaternion3D::Quaternion3D (float angle, const Vector3D& axis) {
    float sinVal = sin(angle/2);
    c = cos(angle/2);
    i = sinVal * axis.getx();
    j = sinVal * axis.gety();
    k = sinVal * axis.getz();
}
Quaternion3D::Quaternion3D (const Vector3D& axis) {
    c = 0;
    i = axis.getx();
    j = axis.gety();
    k = axis.getz();
}

//Simple Properties
float Quaternion3D::magSquared () const {
    return c*c + i*i + j*j + k*k;
}
Quaternion3D Quaternion3D::conjugate () const {
    return Quaternion3D(c, -i, -j, -k);
}
Quaternion3D Quaternion3D::inverse () const {
    float temp = this->magSquared();
    if (temp > 0.99 && temp < 1.01) {
        return this->conjugate();
    } else {
        return 1/sqrt(temp) * this->conjugate();
    }
}
Vector3D Quaternion3D::getVector () const {
    return Vector3D(i, j, k);
}

//Rotate
Vector3D Quaternion3D::rotate (const Vector3D& input) const {
    return (*this * Quaternion3D(input) * this->inverse()).getVector();
}

//Addition
Quaternion3D operator + (const Quaternion3D& left, const Quaternion3D& right) {
    return Quaternion3D(left.c + right.c, left.i + right.i, left.j + right.j, left.k + right.k);
}
Quaternion3D operator - (const Quaternion3D& left, const Quaternion3D& right) {
    return Quaternion3D(left.c - right.c, left.i - right.i, left.j - right.j, left.k - right.k);
}

Quaternion3D& Quaternion3D::operator += (const Quaternion3D& right) {
    this->c += right.c;
    this->i += right.i;
    this->j += right.j;
    this->k += right.k;
    return *this;
}
Quaternion3D& Quaternion3D::operator -= (const Quaternion3D& right) {
    this->c -= right.c;
    this->i -= right.i;
    this->j -= right.j;
    this->k -= right.k;
    return *this;
}

//Scalar Multiplication
Quaternion3D operator * (float scalar, const Quaternion3D& quaternion) {
    return Quaternion3D(scalar * quaternion.c, scalar * quaternion.i, scalar * quaternion.j, scalar * quaternion.k);
}
Quaternion3D operator * (const Quaternion3D& quaternion, float scalar) {
    return scalar * quaternion;
    }
Quaternion3D operator / (const Quaternion3D& quaternion, float scalar) {
    return (1/scalar) * quaternion;
}

Quaternion3D& Quaternion3D::operator *= (float scalar) {
    this->c *= scalar;
    this->i *= scalar;
    this->j *= scalar;
    this->k *= scalar;
    return *this;
}
Quaternion3D& Quaternion3D::operator /= (float scalar) {
    return *this *= (1/scalar);
}

//Quaternion Multiplication
Quaternion3D operator * (const Quaternion3D& left, const Quaternion3D& right) {
    const float c = (left.c * right.c) - (left.i * right.i) - (left.j * right.j) - (left.k * right.k);
    const float i = (left.c * right.i) + (left.i * right.c) + (left.j * right.k) - (left.k * right.j);
    const float j = (left.c * right.j) + (left.j * right.c) + (left.k * right.i) - (left.i * right.k);
    const float k = (left.c * right.k) + (left.k * right.c) + (left.i * right.j) - (left.j * right.i);

    return Quaternion3D(c, i, j, k);
}

#endif