#include "testmatrix.h"


void TestMatrix :: matrixFromStringAndBack()
{
    Matrix4x4 matrix;
    QString inputMatrix = "1 2 3 0\n"
                          "4 6 1 1\n"
                          "3 5 8 0\n"
                          "1 2 1 1\n";
    matrix.matrixFromQTextStream(inputMatrix);
    QString result = matrix.matrixToQString();

    QCOMPARE(QString(result), QString("1 2 3 0 \n"
                                      "4 6 1 1 \n"
                                      "3 5 8 0 \n"
                                      "1 2 1 1 \n"));
}

void TestMatrix :: matricesMultipleTest()
{
    Matrix4x4 matrix1;
    Matrix4x4 matrix2;
    QString inputMatrix1 = "1 2 3 0\n"
                           "4 6 1 1\n"
                           "3 5 8 0\n"
                           "1 2 1 1\n";
    matrix1.matrixFromQTextStream(inputMatrix1);
    QString inputMatrix2 = "3 5 8 0\n"
                              "0 1 1 1\n"
                              "1 2 0 3\n"
                              "1 0 1 1\n";
    matrix2.matrixFromQTextStream(inputMatrix2);
    QString result = (Matrix4x4::multipleMatrixes(matrix1, matrix2)).matrixToQString() ;

    QCOMPARE(QString(result), QString("6 13 10 11 \n"
                                      "14 28 39 10 \n"
                                      "17 36 29 29 \n"
                                      "5 9 11 6 \n"));
}

void TestMatrix :: matrixVectorMultipleTEst()
{
    Matrix4x4 matrix;
    Vertex vertex;
    Vertex *resultVertex = new Vertex();
    QString inputMatrix = "1 2 3 0\n"
                              "4 6 1 1\n"
                              "3 5 8 0\n"
                              "1 2 1 1\n";
    matrix.matrixFromQTextStream(inputMatrix);
    QString inputVertex = "5 -3 1";
    vertex.vertexFromQString(inputVertex);
    ;
    QString result = Matrix4x4::multipleMatrixVertex(matrix, vertex).vertexToQString();

    QCOMPARE(QString(result), QString("2 4 8 1 "));
}
