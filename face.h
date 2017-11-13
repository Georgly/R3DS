#ifndef FACE_H
#pragma once
#define FACE_H
#include <QList>

class Face
{
private:
    QList<int> vertexIndex;
    QList<int> textureCoordIndex;
    QList<int> normalVectorIndex;

public:
    Face();
    bool addFace(QStringList indexes, int maxVertexIndex, int maxTextureCoorIndex, int maxNormalVectorIndex, QString& errorStr);
    QList<int> getVertex();
    QList<int> getNormal();
};

#endif // FACE_H
