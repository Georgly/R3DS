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
    //QWidget *drawArea;
public:
    ModelView();
    QString importModel(QString fileName);
    QString importModel(QTextStream& fileName);
    void exportModel();/*
    Matrix4x4 translationMatrix(float addX, float addY, float addZ);
    Matrix4x4 scalingMatrix(float scalingX, float scalingY, float scalingZ);
    Matrix4x4 rotationMatrix(float xRotationAngle, float yRotationAngle, float zRotationAngle);
    Matrix4x4 lookAtLH(Vertex position, Vertex target, Vertex unitY);
    Matrix4x4 perspectiveFovRH(float v1, float p, float v2, float v3);*/
    Matrix4x4 findTransformMatrix();
    void drawVertexModel(QPainter *painter);
    void drawFaceModel(QPainter *painter);
    //void setWidget(QWidget *widget);
    //void drawVertex(Vertex vertex);
    void drawModel(QPainter *painter);
};

#endif // MODELVIEW_H
