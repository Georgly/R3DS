#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "modelview.h"
#include "viewport.h"
#include "modelsettingswindow.h"

namespace Ui {
class MainWindow;
class ModelSettingsWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 
    void keyPressEvent(QKeyEvent *event);
    void setModelSettings(int zoom, int typeOfProjection, int angle, float nearClipping, float farClipping);

private slots:
    void open();
    bool save();
    void testMatrix();
    void testVector();
    void settings();

private:
    Ui::MainWindow *ui;
    ModelView model;
    QWidget *settingsWindow;
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QMenu *testMenu;
    QMenu *settingsMenu;
    QAction *openSettingsAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *matrixTestAct;
    QAction *vectorTestAct;
};

#endif // MAINWINDOW_H
