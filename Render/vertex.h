#ifndef VERTEX_H
#define VERTEX_H
#include "QString"
#include "QStringList"

class Vertex
{
public:
    float vector[4];// x, y, z, isPosition;
    Vertex();
    Vertex (float x, float y, float z);
    Vertex (float coord);
    void vertexFromQString(QString input);
    QString vertexToQString();
};

#endif // VERTEX_H
