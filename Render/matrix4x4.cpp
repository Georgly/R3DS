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
            if( iteratorRow == iteratorColumn)
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

Vertex Matrix4x4 :: multipleMatrixVertex(Matrix4x4 matrix, Vertex vertex/*, Vertex *out*/)
{
    Vertex *out = new Vertex();
    float halfResult;
    for ( int iteratorRow = 0; iteratorRow < 4; iteratorRow++ )
    {
        halfResult = 0;
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
            halfResult += matrix.matrix[iteratorRow][iteratorColumn] *
                    vertex.vector[iteratorColumn];
        }
        out->vector[iteratorRow] = halfResult;
    }

    if (out->vector[3] != 1)
    {
        out->vector[0] /= out->vector[3];
        out->vector[1] /= out->vector[3];
        out->vector[2] /= out->vector[3];
        out->vector[3] /= out->vector[3];
    }

    return *out;
}

Matrix4x4 Matrix4x4 :: multipleMatrixes(Matrix4x4 matrix1, Matrix4x4 matrix2)
{
    Matrix4x4 *result = new Matrix4x4();
    float halfResult;
    for ( int iteratorRow = 0; iteratorRow < 16; iteratorRow++ )
    {
        halfResult = 0;
        for ( int iteratorColumn = 0; iteratorColumn < 4; iteratorColumn++ )
        {
             halfResult += matrix1.matrix[ iteratorRow / 4 ][iteratorColumn] *
                    matrix2.matrix[iteratorColumn][ iteratorRow % 4 ];
        }
        result->matrix[ iteratorRow / 4 ][ iteratorRow % 4 ] = halfResult;
    }

    return *result;
}

void Matrix4x4 :: matrixFromQTextStream(QString matrixString)
{
    QStringList matrixRow = matrixString.split('\n');
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
    //float xRotationAngle = qDegreesToRadians(xRotationAngle);
    //float yRotationAngle = qDegreesToRadians(yRotationAngle);
    //float zRotationAngle = qDegreesToRadians(zRotationAngle);
    rotationMatrix->matrix[0][0] = qCos(zRotationAngle) * qCos(yRotationAngle);
    rotationMatrix->matrix[1][0] = qSin(zRotationAngle) * qCos(yRotationAngle);
    rotationMatrix->matrix[2][0] = 0 - qSin(yRotationAngle);
    rotationMatrix->matrix[0][1] = qCos(zRotationAngle) * qSin(yRotationAngle) * qSin(xRotationAngle) -
            qSin(zRotationAngle) * qCos(xRotationAngle);
    rotationMatrix->matrix[1][1] = qSin(zRotationAngle) * qSin(yRotationAngle) * qSin(xRotationAngle) +
            qCos(zRotationAngle) * qCos(xRotationAngle);
    rotationMatrix->matrix[2][1] = qCos(yRotationAngle) * qSin(xRotationAngle);
    rotationMatrix->matrix[0][2] = qCos(zRotationAngle) * qSin(yRotationAngle) * qCos(xRotationAngle) -
            qSin(zRotationAngle) * qSin(xRotationAngle);
    rotationMatrix->matrix[1][2] = qSin(zRotationAngle) * qSin(yRotationAngle) * qCos(xRotationAngle) +
            qCos(zRotationAngle) * qSin(xRotationAngle);
    rotationMatrix->matrix[2][2] = qCos(yRotationAngle) * qCos(xRotationAngle);
    return *rotationMatrix;
}

Matrix4x4 Matrix4x4 :: lookAt(Vertex position, Vertex target, Vertex unitY)
{
    Vertex rightn, upn, vec;
    Matrix4x4 *pout = new Matrix4x4();

    vec = Vector3::Normalize(Vector3::Subtract(target, position));
    rightn = Vector3::Normalize(Vector3::Cross(unitY, vec));
    upn = Vector3::Normalize(Vector3::Cross(vec, Vector3::Cross(unitY, vec)));
    pout->matrix[0][0] = rightn.vector[0];
    pout->matrix[0][1] = rightn.vector[1];
    pout->matrix[0][2] = rightn.vector[2];
    pout->matrix[0][3] = -Vector3::Dot(rightn, position);
    pout->matrix[1][0] = upn.vector[0];
    pout->matrix[1][1] = upn.vector[1];
    pout->matrix[1][2] = upn.vector[2];
    pout->matrix[1][3] = -Vector3::Dot(upn, position);
    pout->matrix[2][0] = vec.vector[0];
    pout->matrix[2][1] = vec.vector[1];
    pout->matrix[2][2] = vec.vector[2];
    pout->matrix[2][3] = -Vector3::Dot(vec, position);
    return *pout;
}

Matrix4x4 Matrix4x4 :: perspectiveFovRH(float v1, float p, float v2, float v3)//
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

Matrix4x4 Matrix4x4::perspectiveProjectionMatrix(float angleOfView, float imageAspectRatio, float n, float f)
{
    Matrix4x4 *out = new Matrix4x4();

    float scale = tan(angleOfView * 0.5 * M_PI / 180) * n;
    float r = imageAspectRatio * scale;
    float l = -r;
    float t = scale;
    float b = -t;

    out->matrix[0][0] = 2 * n / (r - l);
    out->matrix[0][2] = (r + l) / (r - l);

    out->matrix[1][1] = 2 * n / (t - b);
    out->matrix[1][2] = (t + b) / (t - b);

    out->matrix[2][2] = -(f + n) / (f - n);
    out->matrix[2][3] = -2 * f * n / (f - n);

    out->matrix[3][2] = -1;
    out->matrix[3][3] = 0;

    return *out;
}

Matrix4x4 Matrix4x4::orthographicProjectionMatrix(Vertex minWorld, Vertex maxWorld,
                                             float imageAspectRatio,
                                             float n, float f,
                                             Matrix4x4 worldToCamera)
{
    Matrix4x4 *out = new Matrix4x4();
    Vertex minCamera, maxCamera;
    minCamera = multipleMatrixVertex(worldToCamera, minWorld);
    maxCamera = multipleMatrixVertex(worldToCamera, maxWorld);

    float maxx = std::max(fabs(minCamera.vector[0]), fabs(maxCamera.vector[0]));
    float maxy = std::max(fabs(minCamera.vector[1]), fabs(maxCamera.vector[1]));

    float max = (maxx < maxy ? maxy : maxx);
    float r = max * imageAspectRatio, t = max;
    float l = -r, b = -t;

    out->matrix[0][0] = 2 / (r - l);
    out->matrix[0][3] = -(r + l) / (r - l);

    out->matrix[1][1] = 2 / (t - b);
    out->matrix[1][3] = -(t + b) / (t - b);

    out->matrix[2][2] = -2 / (f - n);
    out->matrix[2][3] = -(f + n) / (f - n);

    out->matrix[3][3] = 1;

    return *out;
}

const Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right)
{
    return Matrix4x4::multipleMatrixes(left, right);
}
