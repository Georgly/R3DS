#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QWidget>
#include <QPainter>
#include "modelview.h"

class Viewport : public QWidget
{
    Q_OBJECT
public:
    explicit Viewport(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void setModel(ModelView *model);
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

private:
    ModelView *model;
};

#endif // VIEWPORT_H
