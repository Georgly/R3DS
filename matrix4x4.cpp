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

Vertex Matrix4x4 :: multipleMatrixVertex(Matrix4x4 matrix, Vertex vertex)
{
    Vertex *result = new Vertex();
    for ( int iteratorRow = 0; iteratorRow < 4; iteratorRow++ )
    {
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
            result->vector[iteratorRow] += matrix.matrix[iteratorRow][iteratorColumn] * vertex.vector[iteratorColumn];
        }
    }

    return *result;
}

Matrix4x4 Matrix4x4 :: multipleMatrixes(Matrix4x4 matrix1, Matrix4x4 matrix2)
{
    Matrix4x4 *result = new Matrix4x4();
    for ( int iteratorRow = 0; iteratorRow < 16; iteratorRow++ )
    {
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
            result->matrix[ iteratorRow / 4 ][ iteratorRow % 4 ] +=
                    matrix1.matrix[ iteratorRow / 4 ][iteratorColumn] * matrix2.matrix[iteratorColumn][ iteratorRow % 4 ];
        }
    }

    return *result;
}

void Matrix4x4 :: matrixFromQTextStream(QTextStream &matrixString)
{
    QString inputStr = matrixString.readAll();
    QStringList matrixRow = inputStr.split('\n');
    for( int iteratorRow = 0; iteratorRow < matrixRow.count(); iteratorRow++ )
    {
        QStringList matrixColumn = matrixRow[iteratorRow].split(' ', QString::SkipEmptyParts);
        for ( int iteratorColumn = 0; iteratorColumn < matrixColumn.count(); iteratorColumn++ )
        {
            this->matrix[iteratorRow][iteratorColumn] = matrixColumn[iteratorColumn].toFloat();
        }
    }
}

QString Matrix4x4 :: matrixToQString()
{
    QString result = "";
    for (int iteratorRow = 0; iteratorRow < 4; iteratorRow++)
    {
        for (int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++)
        {
            result += QString::number(matrix[iteratorRow][iteratorColumn]) + " ";
        }
        result += "\n";
    }
    return result;
}

Matrix4x4 Matrix4x4 :: translationMatrix(float addX, float addY, float addZ)
{
    Matrix4x4 *translationMatrix = new Matrix4x4();//maybe pass matrix by reference
    translationMatrix->matrix[0][3] = addX;
    translationMatrix->matrix[1][3] = addY;
    translationMatrix->matrix[2][3] = addZ;
    return *translationMatrix;
}

Matrix4x4 Matrix4x4 :: scalingMatrix(float scalingX, float scalingY, float scalingZ)
{
    Matrix4x4 *scalingMatrix = new Matrix4x4();//maybe pass matrix by reference
    scalingMatrix->matrix[0][0] = (scalingX == 0 ? 1 : scalingX);
    scalingMatrix->matrix[1][1] = (scalingY == 0 ? 1 : scalingY);
    scalingMatrix->matrix[2][2] = (scalingZ == 0 ? 1 : scalingZ);
    return *scalingMatrix;
}

Matrix4x4 Matrix4x4 :: rotationMatrix(float xRotationAngle, float yRotationAngle, float zRotationAngle)
{
    Matrix4x4 *rotationMatrix = new Matrix4x4();
    float xRadians = qDegreesToRadians(xRotationAngle);
    float yRadians = qDegreesToRadians(yRotationAngle);
    float zRadians = qDegreesToRadians(zRotationAngle);
    rotationMatrix->matrix[0][0] = qCos(zRadians) * qCos(yRadians);
    rotationMatrix->matrix[1][0] = qSin(zRadians) * qCos(yRadians);
    rotationMatrix->matrix[2][0] = 0 - qSin(yRadians);
    rotationMatrix->matrix[0][1] = qCos(zRadians) * qSin(yRadians) * qSin(xRadians) -
            qSin(zRadians) * qCos(xRadians);
    rotationMatrix->matrix[1][1] = qSin(zRadians) * qSin(yRadians) * qSin(xRadians) +
            qCos(zRadians) * qCos(xRadians);
    rotationMatrix->matrix[2][1] = qCos(yRadians) * qSin(xRadians);
    rotationMatrix->matrix[0][2] = qCos(zRadians) * qSin(yRadians) * qCos(xRadians) -
            qSin(zRadians) * qSin(xRadians);
    rotationMatrix->matrix[1][2] = qSin(zRadians) * qSin(yRadians) * qCos(xRadians) +
            qCos(zRadians) * qSin(xRadians);
    rotationMatrix->matrix[2][2] = qCos(yRadians) * qCos(xRadians);
    return *rotationMatrix;
}

Matrix4x4 Matrix4x4 :: lookAtLH(Vertex position, Vertex target, Vertex unitY)
{
    Vertex *rightn, *upn, *vec;
    Matrix4x4 *pout = new Matrix4x4();

    *vec = Vector3::Normalize(Vector3::Subtract(target, position));
    *rightn = Vector3::Normalize(Vector3::Cross(unitY, *vec));
    *upn = Vector3::Normalize(Vector3::Cross(*vec, Vector3::Cross(unitY, *vec)));
    pout->matrix[0][0] = rightn->vector[0];
    pout->matrix[1][0] = rightn->vector[1];
    pout->matrix[2][0] = rightn->vector[2];
    pout->matrix[3][0] = -Vector3::Dot(*rightn, position);
    pout->matrix[0][1] = upn->vector[0];
    pout->matrix[1][1] = upn->vector[1];
    pout->matrix[2][1] = upn->vector[2];
    pout->matrix[3][1] = -Vector3::Dot(*upn, position);
    pout->matrix[0][2] = vec->vector[0];
    pout->matrix[1][2] = vec->vector[1];
    pout->matrix[2][2] = vec->vector[2];
    pout->matrix[3][2] = -Vector3::Dot(*vec, position);
    return *pout;
}

Matrix4x4 Matrix4x4 :: perspectiveFovRH(float v1, float p, float v2, float v3)
{
    float yScale = 1 / (float)qTan(/*(Math.PI * v1 / 180)*/v1 / 2);
    float xScale = yScale / p;
    Matrix4x4 *result = new Matrix4x4();

    result->matrix[0][0] = xScale;
    result->matrix[1][1] = yScale;
    result->matrix[2][2] = v3 / (v2 - v3);
    result->matrix[2][3] = -1;
    result->matrix[3][2] = v2 * v3 / (v2 - v3);

    return *result;
}

const Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right) {
    return Matrix4x4::multipleMatrixes(left, right);
}
