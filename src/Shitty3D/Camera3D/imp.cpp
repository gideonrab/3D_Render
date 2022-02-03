#ifndef Camera3D_imp_cpp
#define Camera3D_imp_cpp

#include "def.h"

Camera3D::Camera3D () {
    position = Vector3D();
    rotation = Quaternion3D();
    viewWidth = 1;
}
Camera3D::Camera3D (const Vector3D& _position, const Quaternion3D& _rotation, const float _fieldOfView) {
    position = _position;
    rotation = _rotation;
    viewWidth = 1/_fieldOfView;
}

Vector3D Camera3D::transformPoint (Vector3D& point) const {
    Vector3D temp = point - position;
    return rotation.conjugate().rotate(temp);
}

Vector3D Camera3D::flattenPoint (Vector3D& point) const {
    return Vector3D(viewWidth*point.getx()/point.getz(), viewWidth*point.gety()/point.getz(), point.getz());
}

Vector3D Camera3D::projectPoint (Vector3D& point) const {
    Vector3D temp = this-> transformPoint(point);
    return this->flattenPoint(temp);
}

#endif