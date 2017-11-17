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
    //model.setWidget(ui->drawSpaceWidg);
    Viewport *viewport = new Viewport();

    static_cast<QVBoxLayout*>(ui->enteractivePanel->layout())->setAlignment(Qt::AlignTop);
    static_cast<QHBoxLayout*>(centralWidget()->layout())->addWidget(viewport,1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFileBt_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    model.importModel(fileName);
}

void MainWindow::on_drawModelBt_clicked()
{
    //model.drawVertexModel();
    //update();
}

void MainWindow::on_pushButton_clicked()
{
    model.exportModel();
}

void MainWindow::on_testMatrixBt_clicked()
{
    TestMatrix tests;
    QTest::qExec(&tests);
}

void MainWindow::on_testVectorBt_clicked()
{
    TestVector tests;
    QTest::qExec(&tests);
}
