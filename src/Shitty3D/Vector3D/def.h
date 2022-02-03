#ifndef Vector3D_def_h
#define Vector3D_def_h

#include "fwd.h"

#include "../Quaternion3D/fwd.h"

class Vector3D {
    private:
    float x;
    float y;
    float z;

    public:
    Vector3D ();
    Vector3D (float x, float y, float z);

    float getx () const {return x;}
    float gety () const {return y;}
    float getz () const {return z;}

    //Simple Properties
    float magSquared () const;

    //Addition
    friend Vector3D operator + (const Vector3D&, const Vector3D&);
    friend Vector3D operator - (const Vector3D&, const Vector3D&);

    Vector3D& operator += (const Vector3D&);
    Vector3D& operator -= (const Vector3D&);

    //Scalar Multiplication
    friend Vector3D operator * (float, const Vector3D&);
    friend Vector3D operator * (const Vector3D&, float);
    friend Vector3D operator / (const Vector3D&, float);

    Vector3D& operator *= (float);
    Vector3D& operator /= (float);

    //Vector Multiplication
    friend Quaternion3D operator * (const Vector3D&, const Vector3D&);
};

#endif