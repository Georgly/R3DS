#ifndef MODELVIEW_H
#define MODELVIEW_H
#include "matrix4x4.h"
#include "QtMath"
#include "vector3.h"
#include "model.h"
#include "camera.h"
#include "QPainter"


class ModelView
{
private:
    Model *mesh = new Model();
    Camera *camera = new Camera();
    int zoom = 2;
    QVector<Vertex> vertexModel;
    int drawAreaHeight = 1;
    int drawAreaWidth = 1;
    int typeOfProjection = 0;
public:
    ModelView();
    QString importModel(QString fileName);
    QString importModel(QTextStream& fileName);
    void exportModel();
    Matrix4x4 findTransformMatrix();
    void drawVertexModel(QPainter *painter);
    void drawFaceModel(QPainter *painter);
    void drawVertex(Vertex vertex, QPainter *painter);
    void drawFace(QPainter *painter, QList<int> indeces);
    void drawModel(QPainter *painter, int widgetHeight, int widgetWidth);
    void scaleModel(QPainter *painter, int scale, int widgetHeight, int widgetWidth);
    void moveModel(QPainter *painter, int deltaX, int deltaY, int widgetHeight, int widgetWidth);
    //void setSettings();//TODO
};

#endif // MODELVIEW_H
