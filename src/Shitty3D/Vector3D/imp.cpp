#ifndef Vector3D_imp_cpp
#define Vector3D_imp_cpp

#include "def.h"

#include "../Quaternion3D/def.h"

//Constructor
Vector3D::Vector3D () {
    x = 0;
    y = 0;
    z = 0;
}
Vector3D::Vector3D (float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

//Simple Properties
float Vector3D::magSquared () const {
    return x*x + y*y + z*z;
}

//Addition
Vector3D operator + (const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
}
Vector3D operator - (const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3D& Vector3D::operator += (const Vector3D& right) {
    this->x += right.x;
    this->y += right.y;
    this->z += right.z;
    return *this;
}
Vector3D& Vector3D::operator -= (const Vector3D& right) {
    this->x -= right.x;
    this->y -= right.y;
    this->z -= right.z;
    return *this;
}

//Scalar Multiplication
Vector3D operator * (float scalar, const Vector3D& vector) {
    return Vector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}
Vector3D operator * (const Vector3D& vector, float scalar) {
    return scalar * vector;
}
Vector3D operator / (const Vector3D& vector, float scalar) {
    return (1/scalar) * vector;}

Vector3D& Vector3D::operator *= (float scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}
Vector3D& Vector3D::operator /= (float scalar) {
    return *this *= (1/scalar);
}

//Vector Multiplication
Quaternion3D operator * (const Vector3D& left, const Vector3D& right) {
    const float c = (left.x * right.x) + (left.y * right.y) + (left.z + right.z);
    const float i = (left.y * right.z) - (left.z * right.y);
    const float j = (left.z * right.x) - (left.x * right.z);
    const float k = (left.x * right.y) - (left.y * right.x);

    return Quaternion3D(c, i, j, k);
}

#endif