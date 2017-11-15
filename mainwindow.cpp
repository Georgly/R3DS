#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model.setWidget(ui->drawSpaceWidg);
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
    model.drawVertexModel();
}

void MainWindow::on_pushButton_clicked()
{
    model.exportModel();
}
