#include "matrix4x4.h"

Matrix4x4::Matrix4x4()
{
    Initialization();
}

void Matrix4x4 :: Initialization()
{
    for (int iteratorRow = 0; iteratorRow < 4; iteratorRow++)
    {
        for (int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++)
        {
            if ( iteratorRow == iteratorColumn )
            {
                matrix[iteratorRow][iteratorColumn] = 1;
            }
            else
            {
                matrix[iteratorRow][iteratorColumn] = 0;
            }
        }
    }
}

Vertex Matrix4x4 :: MultipleMatrixVertex(Matrix4x4 matrix, Vertex vertex)
{
    Vertex *result = new Vertex();
    for ( int iteratorRow = 0; iteratorRow < 4; iteratorRow++ )
    {
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
            result.vector[iteratorRow] += matrix[iteratorRow][iteratorColumn] * vertex[iteratorColumn];
        }
    }

    return result;
}

Matrix4x4 Matrix4x4 :: MultipleMatrixes(Matrix4x4 matrix1, Matrix4x4 matrix2)
{
    Matrix4x4 *result = new Matrix4x4();
    for ( int iteratorRow = 0; iteratorRow < 16; iteratorRow++ )
    {
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
            result->matrix[ iteratorRow / 4 ][ iteratorRow % 4 ] +=
                    matrix1[ iteratorRow / 4 ][iteratorColumn] * vertex2[iteratorColumn][ iteratorRow % 4 ];
        }
    }

    return result;
}
