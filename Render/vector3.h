#ifndef VECTOR3_H
#define VECTOR3_H
#include "vertex.h"
#include "QtMath"

class Vector3
{
public:
    Vector3();
    static Vertex Subtract(Vertex v1, Vertex v2);
    static Vertex Cross(Vertex v1, Vertex v2);
    static Vertex Normalize(Vertex v);
    static float Dot(Vertex v1, Vertex v2);
    static float Length(Vertex v1);
};

#endif // VECTOR3_H
