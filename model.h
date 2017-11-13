#ifndef MODEL_H
#define MODEL_H
#include "face.h"
#include "vertex.h"
#include "normalvector.h"
#include "texturecoord.h"
#include <QVector>
#include <QTextStream>
#include <QMessageBox>

class Model
{
private:
    QVector<Vertex> vertexModel;
    QVector<NormalVector> normalVectorModel;
    QVector<TextureCoord> textureCoordModel;
    QVector<Face> faceModel;
    QVector<QString> fileStrList;

public:
    Model();
    QString importModel(QString fileName);
    QString importModel(QTextStream& fileName);
    void exportModel();
    /*QTextStream**/QString parseFIle(QString fileName);

private:
    QString faceToString(Face face);
    bool addNewFace(QStringList vertexStr, QString& errorStr);
    bool isFaceCorrectFormat(QStringList vertexStr, QString& errStr);
    bool addNewTextureCoord(QStringList vertexStr, QString& errorStr);
    bool addNewNormalVector(QStringList vertexStr, QString& errorStr);
    bool addNewVertex(QStringList vertexStr, QString& errorStr);
    bool isVertexCorrectFormat(QStringList vertexStr, QString& errorStr);
};

#endif // MODEL_H
