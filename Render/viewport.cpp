#include "viewport.h"
#include <QPainter>

Viewport::Viewport(QWidget *parent) : QWidget(parent)
{

}

void Viewport::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    model->drawModel(&painter);
}

void Viewport::setModel(ModelView *model)
{
    this->model = model;
}
