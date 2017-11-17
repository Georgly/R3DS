#ifndef TESTMATRIX_H
#define TESTMATRIX_H

#include <QObject>
#include <QTest>
#include "matrix4x4.h"

class TestMatrix : public QObject
{
    Q_OBJECT

private slots:
    void matrixFromStringAndBack();
    void matricesMultipleTest();
    void matrixVectorMultipleTEst();
};

#endif // TESTMATRIX_H
