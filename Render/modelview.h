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
    QVector<Vertex> vertexModel;
    //-----------
    int zoom = 1;
    int drawAreaHeight = 1;
    int drawAreaWidth = 1;
    int typeOfProjection = 0;
    int angle = 90;
    float nearClipping = 0.1;
    float farClipping = 100;
    //------------
    void TestDraw(QPainter *painter);
public:
    ModelView();
    QString importModel(QString fileName);
    QString importModel(QTextStream& fileName);
    void exportModel();
    Matrix4x4 findTransformMatrix();
    //--------drawing---------
    void drawVertexModel(QPainter *painter);
    void drawFaceModel(QPainter *painter);
    void drawVertex(Vertex vertex, QPainter *painter);
    void drawFace(QPainter *painter, QList<int> indeces);
    void drawModel(QPainter *painter, int widgetHeight, int widgetWidth);
    //--------model transformation---------
    void scaleModel(QPainter *painter, int scale, int widgetHeight, int widgetWidth);
    void moveModel(QPainter *painter, int deltaX, int deltaY, int deltaZ, int widgetHeight, int widgetWidth);
    void moveCamera(int deltaX, int deltaY, int deltaZ);
    void rotateModel(int angleX, int angleY, int angleZ);
    void setSettings(int zoom, int typeOfProjection, int angle, float nearClipping, float farClipping);//TODO
};

#endif // MODELVIEW_H
