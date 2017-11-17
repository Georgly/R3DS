#include "testvector.h"

void TestVector :: testVertexFromStringAndBack()
{
    Vertex vertex;
    QString input = "1 5 9";
    vertex.vertexFromQString(input);
    QString result = vertex.vertexToQString();

    QCOMPARE(QString(result), QString("1 5 9 1 "));
}

void TestVector :: testVectorNormalization()
{
    Vertex vertex;
    QString input = "1 0 0";
    vertex.vertexFromQString(input);
    QString result = Vector3::Normalize(vertex).vertexToQString();

    QCOMPARE(QString(result), QString("1 0 0 1 "));
}

void TestVector :: testVectorLength()
{
    Vertex vertex;
    QString input = "1 2 2";
    vertex.vertexFromQString(input);
    QString result = QString::number(Vector3::Length(vertex));

    QCOMPARE(QString(result), QString(QString::number(3)));
}

void TestVector :: testVectorSubtract()
{
    Vertex vertex1;
    QString input1 = "1 2 4";
    vertex1.vertexFromQString(input1);
    Vertex vertex2;
    QString input2 = "3 1 2";
    vertex2.vertexFromQString(input2);
    QString result = Vector3::Subtract(vertex1, vertex2).vertexToQString();

    QCOMPARE(QString(result), QString("-2 1 2 1 "));
}

void TestVector :: testVectorCross()
{

}

void TestVector :: testVectorDot()
{
    Vertex vertex1;
    QString input1 = "1 -2 4";
    vertex1.vertexFromQString(input1);
    Vertex vertex2;
    QString input2 = "-3 1 2";
    vertex2.vertexFromQString(input2);
    QString result = QString::number(Vector3::Dot(vertex1, vertex2));

    QCOMPARE(QString(result), QString(QString::number(3)));
}
