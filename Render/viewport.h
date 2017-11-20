#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QWidget>
#include "modelview.h"

class Viewport : public QWidget
{
    Q_OBJECT
public:
    explicit Viewport(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setModel(ModelView *model);
signals:

public slots:

private:
    ModelView *model;
};

#endif // VIEWPORT_H
