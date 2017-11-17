#include "modelview.h"


ModelView :: ModelView()
{
    camera->position = new Vertex(0, 0, 15);
    camera->target = new Vertex();
}

QString ModelView :: importModel(QString fileName)
{
    mesh->importModel(fileName);
}

QString ModelView :: importModel(QTextStream &fileName)
{
    mesh->importModel(fileName);
}

void ModelView :: exportModel()
{
    mesh->exportModel();
}

Matrix4x4 ModelView :: findTransformMatrix()
{
    Matrix4x4 viewMatrix = Matrix4x4::lookAtLH(*camera->position, *camera->target, *(new Vertex(0, 1, 0)));
    Matrix4x4 projectionMatrix = Matrix4x4::perspectiveFovRH(90, (float)(1920 / 1080), 0.1f, 100.0f);

    Matrix4x4 worldMatrix = Matrix4x4::translationMatrix(mesh->position->vector[0], mesh->position->vector[1], mesh->position->vector[2]) *
            Matrix4x4::rotationMatrix(mesh->rotation->vector[0], mesh->rotation->vector[1], mesh->rotation->vector[2]) *
            Matrix4x4::scalingMatrix(1, 1, 1);

    return projectionMatrix * viewMatrix * worldMatrix;
}

void ModelView :: drawVertexModel(QPainter *painter)
{
//    int length = mesh->vertexModel.count();
//    for (int iterator = 0; iterator < length; iterator++ )
//    {
//        mesh->vertexModel[iterator] = Matrix4x4::multipleMatrixVertex( findTransformMatrix(), mesh->vertexModel[iterator] );
//        drawVertex(mesh->vertexModel[iterator]);
//    }
//    QPainter painter(drawArea);
//    painter.setBrush(Qt::blue);
//    painter.drawPoint(25, 25);
}

//void ModelView :: setWidget(QWidget *widget)
//{
//    //drawArea = widget;
//}

//void ModelView :: drawVertex(Vertex vertex)
//{
//    QPainter painter;
//    painter.drawPoint(vertex.vector[0], vertex.vector[1]);
//}

void ModelView::drawFaceModel(QPainter *painter)
{

}

void ModelView::drawModel(QPainter *painter)
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    painter->setPen(pen);

    painter->drawPoint(25, 25);
    painter->drawLine(13, 14, 20, 17);
}
