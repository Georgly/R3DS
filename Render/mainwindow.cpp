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
    //static_cast<QHBoxLayout*>(centralWidget()->layout())->addWidget(viewport,1);
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
}

void MainWindow::createMenus()
{
  fileMenu = new QMenu("File");
  fileMenu->addAction(openAct);
  fileMenu->addAction(saveAct);
  testMenu = new QMenu("Test");
  testMenu->addAction(matrixTestAct);
  testMenu->addAction(vectorTestAct);
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
