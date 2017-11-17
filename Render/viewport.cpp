#include "viewport.h"
#include <QPainter>

Viewport::Viewport(QWidget *parent) : QWidget(parent)
{

}

void Viewport::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(),Qt::red);
}
