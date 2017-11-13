#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include "vertex.h"

class Matrix4x4
{
private:
    float matrix[4][4];
    void Initialization();
public:
    Matrix4x4();
    Vertex MultipleMatrixVertex(Matrix4x4 matrix, Vertex Vertex);
    Matrix4x4 MultipleMatrixes(Matrix4x4 matrix1, Matrix4x4 matrix2);
};

#endif // MATRIX4X4_H
