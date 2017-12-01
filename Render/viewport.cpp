#include "viewport.h"

Viewport::Viewport(QWidget *parent) : QWidget(parent)
{
}

void Viewport::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.begin(this);

    model->drawModel(&painter, this->height(), this->width());
    painter.end();
}

void Viewport::setModel(ModelView *model)
{
    this->model = model;
}

void Viewport::wheelEvent(QWheelEvent *event)
{
    QPainter painter(this);

    model->scaleModel(&painter, (event->delta() > 0) ? 3 : -3, this->height(), this->width());
    update();
}

void Viewport::keyPressEvent(QKeyEvent *event)
{
    QPainter painter(this);
    int deltaX =0, deltaY = 0;
    switch (event->key())
    {
    case Qt::Key_Up:
    {
        deltaY += 15;
        break;
    }
    case Qt::Key_Down:
    {
        deltaY -= 15;
        break;
    }
    case Qt::Key_Left:
    {
        deltaX -= 15;
        break;
    }
    case Qt::Key_Right:
    {
        deltaX += 15;
        break;
    }
    }
    model->moveModel(&painter, deltaX, deltaY, this->height(), this->width());
    update();
}
