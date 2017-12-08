#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include "testmatrix.h"
#include "testvector.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    Viewport *viewport = new Viewport();
    ui->menuBar->addMenu(fileMenu);
    ui->menuBar->addMenu(testMenu);
    ui->menuBar->addMenu(settingsMenu);
    //static_cast<QHBoxLayout*>(centralWidget()->layout())->addWidget(viewport,1);

    settingsWindow = new ModelSettingsWindow(this);
    ui->centralWidget->layout()->addWidget(viewport);
    viewport->setModel(&model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    //-------------------Open obj-File------------------------
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a new model file"));
    connect(openAct, SIGNAL(triggered(bool)), this, SLOT(open()));
    //------------------Open as obj-File----------------------
    saveAct = new QAction(tr("Save"), this);
    saveAct->setShortcut(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save model"));
    connect(saveAct, SIGNAL(triggered(bool)), this, SLOT(save()));
    //---------------------Test Matrix------------------------
    matrixTestAct = new QAction(tr("Test &Matrix"), this);
    matrixTestAct->setStatusTip(tr("Run matrix tests"));
    connect(matrixTestAct, SIGNAL(triggered(bool)), this, SLOT(testMatrix()));
    //---------------------Test Vector------------------------
    vectorTestAct = new QAction(tr("Test &Vector"), this);
    vectorTestAct->setStatusTip(tr("Run vector tests"));
    connect(vectorTestAct, SIGNAL(triggered(bool)), this, SLOT(testVector()));
    //---------------------Open settings----------------------
    openSettingsAct = new QAction(tr("Settings"), this);
    openSettingsAct->setStatusTip(tr("Open model settings"));
    connect(openSettingsAct, SIGNAL(triggered(bool)), this, SLOT(settings()));
}

void MainWindow::createMenus()
{
  fileMenu = new QMenu("File");
  fileMenu->addAction(openAct);
  fileMenu->addAction(saveAct);
  testMenu = new QMenu("Test");
  testMenu->addAction(matrixTestAct);
  testMenu->addAction(vectorTestAct);
  settingsMenu = new QMenu("Settings");
  settingsMenu->addAction(openSettingsAct);
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (!fileName.isEmpty())
    model.importModel(fileName);
}

bool MainWindow::save()
{
    model.exportModel();
    return true;
}

void MainWindow::testMatrix()
{
    TestMatrix tests;
    QTest::qExec(&tests);
}

void MainWindow::testVector()
{
    TestVector tests;
    QTest::qExec(&tests);
}

void MainWindow::settings()
{
    settingsWindow->show();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QPainter painter(this);
    int delta = 10;
    int deltaX =0, deltaY = 0, deltaZ = 0;
    int cameraX = 0, cameraY = 0, cameraZ = 0;
    int angleX = 0, angleY = 0, angleZ = 0;
    switch (event->key())
    {
    //----- move model ------
    case Qt::Key_Up:
    {
        deltaY += delta;
        break;
    }
    case Qt::Key_Down:
    {
        deltaY -= delta;
        break;
    }
    case Qt::Key_Left:
    {
        deltaX -= delta;
        break;
    }
    case Qt::Key_Right:
    {
        deltaX += delta;
        break;
    }
    case Qt::Key_B:
    {
        deltaZ -= delta;
        break;
    }
    case Qt::Key_N:
    {
        deltaZ += delta;
        break;
    }
    // ------ move camera ------
    case Qt::Key_I:// camera y - up
    {
        cameraY += delta;
        break;
    }
    case Qt::Key_K:// camera y - down
    {
        cameraY -= delta;
        break;
    }
    case Qt::Key_J:// camera x - left
    {
        cameraX -= delta;
        break;
    }
    case Qt::Key_L:// camera x - rigth
    {
        cameraX += delta;
        break;
    }
    case Qt::Key_U:
    {
        cameraZ -= delta;
        break;
    }
    case Qt::Key_O:
    {
        cameraZ += delta;
        break;
    }
    // --------rotate model---------
    case Qt::Key_T:// rotate y - up
    {
        cameraY += delta;
        break;
    }
    case Qt::Key_G:// rotate y - down
    {
        cameraY -= delta;
        break;
    }
    case Qt::Key_F:// rotate x - left
    {
        cameraX -= delta;
        break;
    }
    case Qt::Key_H:// rotate x - rigth
    {
        cameraX += delta;
        break;
    }
    case Qt::Key_R:
    {
        cameraZ -= delta;
        break;
    }
    case Qt::Key_Y:
    {
        cameraZ += delta;
        break;
    }
    }
    //painter.begin(centralWidget());
    model.moveModel(&painter, deltaX, deltaY, deltaZ, centralWidget()->height(), centralWidget()->width());
    model.moveCamera(cameraX, cameraY, cameraZ);
    model.rotateModel(angleX, angleY, angleZ);
    centralWidget()->update();
    //painter.end();
}

void MainWindow::setModelSettings(int zoom, int typeOfProjection, int angle, float nearClipping, float farClipping)
{
    model.setSettings(zoom, typeOfProjection, angle, nearClipping, farClipping);
}
