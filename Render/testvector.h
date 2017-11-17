#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include <QObject>
#include <QTest>
#include "vertex.h"
#include "vector3.h"

class TestVector: public QObject
{
    Q_OBJECT

private slots:
    void testVertexFromStringAndBack();
    void testVectorNormalization();
    void testVectorLength();
    void testVectorSubtract();
    void testVectorCross();
    void testVectorDot();
};

#endif // TESTVECTOR_H
