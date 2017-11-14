#ifndef MODELVIEW_H
#define MODELVIEW_H
#include "matrix4x4.h"
#include "QtMath"
#include "vector3.h"


class ModelView
{
public:
    ModelView();/*
    Matrix4x4 translationMatrix(float addX, float addY, float addZ);
    Matrix4x4 scalingMatrix(float scalingX, float scalingY, float scalingZ);
    Matrix4x4 rotationMatrix(float xRotationAngle, float yRotationAngle, float zRotationAngle);
    Matrix4x4 lookAtLH(Vertex position, Vertex target, Vertex unitY);
    Matrix4x4 perspectiveFovRH(float v1, float p, float v2, float v3);*/
};

#endif // MODELVIEW_H
