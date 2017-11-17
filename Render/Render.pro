#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T13:34:44
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Render
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    vertex.cpp \
    texturecoord.cpp \
    matrix4x4.cpp \
    modelview.cpp \
    vector3.cpp \
    model.cpp \
    face.cpp \
    normalvector.cpp \
    camera.cpp \
    testmatrix.cpp \
    testvector.cpp \
    drawmodelviewer.cpp \
    viewport.cpp

HEADERS += \
        mainwindow.h \
    vertex.h \
    texturecoord.h \
    matrix4x4.h \
    modelview.h \
    vector3.h \
    model.h \
    face.h \
    normalvector.h \
    camera.h \
    testmatrix.h \
    testvector.h \
    drawmodelviewer.h \
    viewport.h

FORMS += \
        mainwindow.ui
