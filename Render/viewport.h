#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QWidget>

class Viewport : public QWidget
{
    Q_OBJECT
public:
    explicit Viewport(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // VIEWPORT_H
