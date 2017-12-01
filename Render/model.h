#ifndef MODEL_H
#define MODEL_H
#include "face.h"
#include "vertex.h"
#include "normalvector.h"
#include "texturecoord.h"
#include "matrix4x4.h"
#include <QVector>
#include <QTextStream>
#include <QMessageBox>

class Model
{
public:
    QVector<Vertex> vertexModel;
    QVector<NormalVector> normalVectorModel;
    QVector<TextureCoord> textureCoordModel;
    QVector<Face> faceModel;
    QVector<QString> fileStrList;

    Vertex *position = new Vertex(0);
    Vertex *rotation = new Vertex(0);
    Vertex *minVertex = new Vertex( std::numeric_limits<float>::max() );
    Vertex *maxVertex = new Vertex( -std::numeric_limits<float>::max() );
    Model();
    QString importModel(QString fileName);
    QString importModel(QTextStream& fileName);
    void exportModel();
    /*QTextStream**/QString parseFIle(QString fileName);
    //void createModel(Matrix4x4 transformMatrix);

private:
    QString faceToString(Face face);
    bool addNewFace(QStringList vertexStr, QString& errorStr);
    bool isFaceCorrectFormat(QStringList vertexStr, QString& errStr);
    bool addNewTextureCoord(QStringList vertexStr, QString& errorStr);
    bool addNewNormalVector(QStringList vertexStr, QString& errorStr);
    bool addNewVertex(QStringList vertexStr, QString& errorStr);
    bool isVertexCorrectFormat(QStringList vertexStr, QString& errorStr);
    void setMinMaxVertex(Vertex vertex);
};

#endif // MODEL_H
