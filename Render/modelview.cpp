#include "modelview.h"


ModelView :: ModelView()
{
    camera->position = new Vertex(100, 100, -1);
    camera->target = new Vertex(100, 100, 0);
    mesh->position = new Vertex(100, 100, 0);
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
    Vertex *changedVertex = new Vertex();
    //Vertex changedVertex;
    for (int iterator = 0; iterator < length; iterator++ )
    {
        vertexModel[iterator] = Matrix4x4::multipleMatrixVertex( findTransformMatrix(), mesh->vertexModel[iterator]);
        if ( typeOfProjection != 0)
        {
//            /*changedVertex*/vertexModel[iterator] = Matrix4x4::multipleMatrixVertex(
//                        Matrix4x4::perspectiveProjectionMatrix(90, drawAreaWidth / (float)drawAreaHeight, 0.1, 100),
//                        vertexModel[iterator]);
        }
        else
        {
            vertexModel[iterator] = Matrix4x4::multipleMatrixVertex(
                        Matrix4x4::orthographicProjectionMatrix(
                            *mesh->minVertex, *mesh->maxVertex,
                            (drawAreaWidth/(float)drawAreaHeight),
                            0.1, 100,
                            Matrix4x4::lookAtLH(*camera->position,
                                                *camera->target,
                                                *(new Vertex(0, 1, 0)))),
                        vertexModel[iterator]);
        }
        //drawVertex(*changedVertex, painter);
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
    drawAreaHeight = widgetHeight;
    drawAreaWidth = widgetWidth;
    drawVertexModel(painter);
    drawFaceModel(painter);
}

void ModelView::scaleModel(QPainter *painter, int scale, int widgetHeight, int widgetWidth)
{
    zoom += scale;
    //drawModel(painter, widgetHeight, widgetWidth);
}

void ModelView::moveModel(QPainter *painter, int deltaX, int deltaY, int widgetHeight, int widgetWidth)
{
    mesh->position->vector[0] += deltaX;
    mesh->position->vector[1] += deltaY;
    //drawModel(painter, widgetHeight, widgetWidth);
}
