#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "modelview.h"
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
    void open();
    bool save();
    void testMatrix();
    void testVector();

private:
    Ui::MainWindow *ui;
    ModelView model;
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QMenu *testMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *matrixTestAct;
    QAction *vectorTestAct;
};

#endif // MAINWINDOW_H
