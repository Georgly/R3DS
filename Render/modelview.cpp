#include "modelview.h"

ModelView :: ModelView()
{
    camera->position = new Vertex(0, 0, 10);
    camera->target = new Vertex(0, 0, 0);
    mesh->position = new Vertex(0, 0, 0);
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
    Matrix4x4 viewMatrix = Matrix4x4::lookAt(*camera->position,
                                             *camera->target,
                                             *(new Vertex(0, 1, 0)));
    //Matrix4x4 projectionMatrix = Matrix4x4::perspectiveFovRH(90, (float)(drawAreaWidth / drawAreaHeight), 0.1f, 100.0f);

    Matrix4x4 worldMatrix = Matrix4x4::translationMatrix(mesh->position->vector[0], mesh->position->vector[1], mesh->position->vector[2]) *
            Matrix4x4::rotationMatrix(mesh->rotation->vector[0], mesh->rotation->vector[1], mesh->rotation->vector[2]) *
            Matrix4x4::scalingMatrix(zoom, zoom, zoom);

    return /*projectionMatrix * */ viewMatrix * worldMatrix;
}

void ModelView :: drawVertexModel(QPainter *painter)
{
    int length = mesh->vertexModel.count();
    vertexModel = mesh->vertexModel;

    Matrix4x4 viewWorldM = findTransformMatrix();
    Matrix4x4 projectionMatrix;
    if (typeOfProjection != 0)
    {
        projectionMatrix = Matrix4x4::perspectiveProjectionMatrix(90,
                                                                  drawAreaWidth / (float)drawAreaHeight,
                                                                  0.1, 100);
    }
    else
    {
        projectionMatrix = Matrix4x4::orthographicProjectionMatrix(
                    *mesh->minVertex, *mesh->maxVertex,
                    (drawAreaWidth/(float)drawAreaHeight),
                    0.1, 100,
                    /*viewWorldM*/Matrix4x4::lookAt(*camera->position,
                                                    *camera->target,
                                                    *(new Vertex(0, 1, 0))));
    }

    for (int iterator = 0; iterator < length; iterator++ )
    {
        vertexModel[iterator] = Matrix4x4::multipleMatrixVertex( viewWorldM, mesh->vertexModel[iterator]);
        vertexModel[iterator] = Matrix4x4::multipleMatrixVertex( projectionMatrix, vertexModel[iterator]);
//        vertexModel[iterator].vector[0] =
//                (vertexModel[iterator].vector[0] / vertexModel[iterator].vector[2] + 1)
//                * drawAreaWidth / 2;
//        vertexModel[iterator].vector[1] =
//                (1 - (vertexModel[iterator].vector[1]/ vertexModel[iterator].vector[2] /*+ 1*/ + 1) / 2)
//                * drawAreaWidth/* / 2*/;
        drawVertex(vertexModel[iterator], painter);
    }
}

void ModelView :: drawVertex(Vertex vertex, QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::blue);
    painter->setPen(pen);

    painter->drawPoint(vertex.vector[0], vertex.vector[1]);
}

void ModelView::drawFaceModel(QPainter *painter)
{
    int length = mesh->faceModel.count();
    for ( int iterator = 0; iterator < length; iterator++ )
    {
        drawFace(painter, mesh->faceModel[iterator].getVertex());
    }
}

void ModelView::drawFace(QPainter *painter, QList<int> indeces)
{
    QPolygonF face;
    for ( int iterator = 0; iterator < indeces.count(); iterator++ )
    {
        face << QPointF(vertexModel[indeces[iterator] - 1].vector[0],
                vertexModel[indeces[iterator] - 1].vector[1]);
    }
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::blue);
    painter->setPen(pen);

    painter->drawPolygon(face, Qt::WindingFill);
}

void ModelView::drawModel(QPainter *painter, int widgetHeight, int widgetWidth)
{
    if(mesh->vertexModel.count() > 0)
    {
        drawAreaHeight = widgetHeight;
        drawAreaWidth = widgetWidth;
        drawVertexModel(painter);
        drawFaceModel(painter);
    }
    //if(vertexModel.count() > 0) TestDraw(painter);

}
//------remove-------
void ModelView::TestDraw(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawPoint(vertexModel[0].vector[0], vertexModel[0].vector[1]);

    pen.setColor(Qt::blue);
    painter->setPen(pen);
    painter->drawPoint(vertexModel[1].vector[0], vertexModel[1].vector[1]);

    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawPoint(vertexModel[2].vector[0], vertexModel[2].vector[1]);

    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawPoint(vertexModel[3].vector[0], vertexModel[3].vector[1]);
}
//-------------------
void ModelView::scaleModel(QPainter *painter, int scale, int widgetHeight, int widgetWidth)
{
    zoom += scale;
    //drawModel(painter, widgetHeight, widgetWidth);
}

void ModelView::moveModel(QPainter *painter, int deltaX, int deltaY, int deltaZ, int widgetHeight, int widgetWidth)
{
    mesh->position->vector[0] += deltaX;
    mesh->position->vector[1] += deltaY;
    mesh->position->vector[2] += deltaZ;
    //drawModel(painter, widgetHeight, widgetWidth);
}

void ModelView::moveCamera(int deltaX, int deltaY, int deltaZ)
{
    camera->position->vector[0] += deltaX;
    camera->position->vector[1] += deltaY;
    camera->position->vector[2] += deltaZ;
}

void ModelView::rotateModel(int angleX, int angleY, int angleZ)
{
    mesh->rotation->vector[0] += angleX;
    mesh->rotation->vector[1] += angleY;
    mesh->rotation->vector[2] += angleZ;
}

void ModelView::setSettings(int zoom, int typeOfProjection, int angle, float nearClipping, float farClipping)
{
    this->zoom = zoom;
    this->typeOfProjection = typeOfProjection;
    this->angle = angle;
    this->nearClipping = nearClipping;
    this->farClipping = farClipping;
}
