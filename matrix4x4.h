#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include "vertex.h"
#include "QTextStream"
#include "matrix4x4.h"
#include "QtMath"
#include "vector3.h"

class Matrix4x4
{
private:
    void Initialization();
    float matrix[4][4];
public:
    Matrix4x4();
    Vertex multipleMatrixVertex(Matrix4x4 matrix, Vertex Vertex);
    Matrix4x4 multipleMatrixes(Matrix4x4 matrix1, Matrix4x4 matrix2);
    void matrixQTextStream(QTextStream &matrixString);

    static Matrix4x4 translationMatrix(float addX, float addY, float addZ);
    static Matrix4x4 scalingMatrix(float scalingX, float scalingY, float scalingZ);
    static Matrix4x4 rotationMatrix(float xRotationAngle, float yRotationAngle, float zRotationAngle);
    static Matrix4x4 lookAtLH(Vertex position, Vertex target, Vertex unitY);
    static Matrix4x4 perspectiveFovRH(float v1, float p, float v2, float v3);
};

#endif // MATRIX4X4_H
