#ifndef Quaternion3D_def_h
#define Quaternion3D_def_h

#include "fwd.h"

#include "../Vector3D/fwd.h"

class Quaternion3D {
    private:
    float c;
    float i;
    float j;
    float k;

    public:
    Quaternion3D ();
    Quaternion3D (float c, float i, float j, float k);
    Quaternion3D (float angle, const Vector3D& axis);
    Quaternion3D (const Vector3D& vector);
    

    float getc () const { return c; }
    float geti () const { return i; }
    float getj () const { return j; }
    float getk () const { return k; }

    //Simple Properties
    float magSquared () const;
    Quaternion3D conjugate () const;
    Quaternion3D inverse () const;
    Vector3D getVector () const;

    //Rotate
    Vector3D rotate (const Vector3D&) const;

    //Addition
    friend Quaternion3D operator + (const Quaternion3D&, const Quaternion3D&);
    friend Quaternion3D operator - (const Quaternion3D&, const Quaternion3D&);

    Quaternion3D& operator += (const Quaternion3D&);
    Quaternion3D& operator -= (const Quaternion3D&);

    //Scalar Multiplication
    friend Quaternion3D operator * (float, const Quaternion3D&);
    friend Quaternion3D operator * (const Quaternion3D&, float);
    friend Quaternion3D operator / (const Quaternion3D&, float);

    Quaternion3D& operator *= (const float);
    Quaternion3D& operator /= (const float);

    //MultiVector Multiplication
    friend Quaternion3D operator * (const Quaternion3D&, const Quaternion3D&);
};

#endif