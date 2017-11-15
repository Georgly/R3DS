#ifndef TESTMATRIX_H
#define TESTMATRIX_H

#include <QObject>

class TestMatrix : public QObject
{
    Q_OBJECT
public:
    explicit TestMatrix(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TESTMATRIX_H