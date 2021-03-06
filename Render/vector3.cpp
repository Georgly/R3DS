#include "vector3.h"


float Vector3 :: Length(Vertex v1)
{
    float x = v1.vector[0];
    float y = v1.vector[1];
    float z = v1.vector[2];
    //float isDirection = v1.vector[3];
    return qSqrt(x * x + y * y + z * z);// + isDirection * isDirection));
}

Vertex Vector3 :: Subtract(Vertex v1, Vertex v2)
{
    Vertex *result = new Vertex(v1.vector[0] - v2.vector[0], v1.vector[1] - v2.vector[1], v1.vector[2] - v2.vector[2]);
    return *result;
}

Vertex Vector3 :: Cross(Vertex v1, Vertex v2)
{
    float x1 = v1.vector[0];
    float y1 = v1.vector[1];
    float z1 = v1.vector[2];
    float x2 = v2.vector[0];
    float y2 = v2.vector[1];
    float z2 = v2.vector[2];
    Vertex *result = new Vertex(y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2);
    return *result;
}

Vertex Vector3 :: Normalize(Vertex v)
{
    float length = Vector3::Length(v);
    Vertex *result = new Vertex((float)(v.vector[0] / length),
            (float)(v.vector[1] / length),
            (float)(v.vector[2] / length));
    return  *result;
}

float Vector3 :: Dot(Vertex v1, Vertex v2)
{
    return v1.vector[0] * v2.vector[0] + v1.vector[1] * v2.vector[1] + v1.vector[2] * v2.vector[2];
}
