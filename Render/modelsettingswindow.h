#ifndef MODELSETTINGSWINDOW_H
#define MODELSETTINGSWINDOW_H
#include "QGroupBox"
#include "QGridLayout"
#include "QRadioButton"
#include "QLabel"
#include "QLineEdit"
#include "mainwindow.h"

class ModelSettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ModelSettingsWindow(QMainWindow* parent);

private:
    QGroupBox* createProjectionGroupBox();
    QGroupBox* createCameraGroupBox();
    QGroupBox* createViewGroupBox();

    QLineEdit *xPosition;
    QLineEdit *yPosition;
    QLineEdit *zPosition;
    QLineEdit *xTarget;
    QLineEdit *yTarget;
    QLineEdit *zTarget;
    QLineEdit *angle;
    QLineEdit *nearBorder;
    QLineEdit *farBorder;

signals:

public slots:
};

#endif // MODELSETTINGSWINDOW_H
