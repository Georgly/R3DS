#include "modelsettingswindow.h"

ModelSettingsWindow::ModelSettingsWindow(QMainWindow* parent)// : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createProjectionGroupBox(), 0, 0);
    grid->addWidget(createCameraGroupBox(), 1, 0);
    grid->addWidget(createViewGroupBox(), 0, 1);
    setLayout(grid);
}

QGroupBox* ModelSettingsWindow::createProjectionGroupBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("Projection Type"));

    QRadioButton *perspective = new QRadioButton(tr("Perspective"));
    QRadioButton *orthographic = new QRadioButton(tr("Orthographic"));

    orthographic->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(perspective);
    vbox->addWidget(orthographic);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox* ModelSettingsWindow::createCameraGroupBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("Camera"));

    QGroupBox *position = new QGroupBox(tr("Position"));
    QLabel *positionX = new QLabel(tr("x:"));
    QLabel *positionY = new QLabel(tr("y:"));
    QLabel *positionZ = new QLabel(tr("z:"));
    xPosition = new QLineEdit("0");
    yPosition = new QLineEdit("0");
    zPosition = new QLineEdit("10");
    QVBoxLayout *hboxP = new QVBoxLayout;
    hboxP->addWidget(positionX);
    hboxP->addWidget(xPosition);
    hboxP->addWidget(positionY);
    hboxP->addWidget(yPosition);
    hboxP->addWidget(positionZ);
    hboxP->addWidget(zPosition);
    position->setLayout(hboxP);

    QGroupBox *target = new QGroupBox(tr("Target"));
    xTarget = new QLineEdit("0");
    yTarget = new QLineEdit("0");
    zTarget = new QLineEdit("0");
    QLabel *targetX = new QLabel(tr("x:"));
    QLabel *targetY = new QLabel(tr("y:"));
    QLabel *targetZ = new QLabel(tr("z:"));
    QVBoxLayout *hboxT = new QVBoxLayout;
    hboxT->addWidget(targetX);
    hboxT->addWidget(xTarget);
    hboxT->addWidget(targetY);
    hboxT->addWidget(yTarget);
    hboxT->addWidget(targetZ);
    hboxT->addWidget(zTarget);
    target->setLayout(hboxT);

    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(position);
    vbox->addWidget(target);

    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox* ModelSettingsWindow::createViewGroupBox()
{
    QGroupBox *groupBox = new QGroupBox(tr("Field of View"));

    QLabel *angleOfView = new QLabel(tr("Angle:"));
    QLabel *nearClipping = new QLabel(tr("Near Clipping border:"));
    QLabel *farClipping = new QLabel(tr("Far Clipping border:"));
    angle = new QLineEdit("90");
    nearBorder = new QLineEdit("0.1");
    farBorder = new QLineEdit("100");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(angleOfView);
    vbox->addWidget(angle);
    vbox->addWidget(nearClipping);
    vbox->addWidget(nearBorder);
    vbox->addWidget(farClipping);
    vbox->addWidget(farBorder);

    groupBox->setLayout(vbox);

    return groupBox;
}
