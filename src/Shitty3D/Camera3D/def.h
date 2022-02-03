#ifndef Camera3D_def_h
#define Camera3D_def_h

#include "fwd.h"

#include "../Vector3D/def.h"
#include "../Quaternion3D/def.h"

class Camera3D {
    private:
    Vector3D position;
    Quaternion3D rotation;
    float viewWidth;

    public:
    Camera3D ();
    Camera3D (const Vector3D& _position, const Quaternion3D& _rotation, const float _fieldOfView);
    
    //Getters
    Vector3D getPosition () const { return position; }
    Quaternion3D getRotation () const { return rotation; }
    float getFieldOfView () const { return 1/viewWidth; }

    //Setters
    void setPosition (Vector3D& position) { this->position = position; }
    void setRotation (Quaternion3D& rotation) { this->rotation = rotation; }
    void setfieldOfView (float fieldOfView) { this->viewWidth = 1/fieldOfView; }

    void movePosition (Vector3D& position) { this->position += position; }
    void moveRotation (Quaternion3D& rotation) { this->rotation = rotation * this->rotation; }

    //Math
    Vector3D transformPoint (Vector3D& point) const;
    Vector3D flattenPoint (Vector3D& point) const;
    Vector3D projectPoint (Vector3D& point) const;
};

#endif