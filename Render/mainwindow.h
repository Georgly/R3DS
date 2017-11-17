#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelview.h"
#include "QFileDialog"
#include "viewport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFileBt_clicked();

    void on_drawModelBt_clicked();

    void on_pushButton_clicked();

    void on_testMatrixBt_clicked();

    void on_testVectorBt_clicked();

private:
    Ui::MainWindow *ui;
    ModelView model;
protected:
};

#endif // MAINWINDOW_H
