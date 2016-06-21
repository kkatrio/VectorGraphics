#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include "renderarea.h"

class QGraphicsView;
class QGraphicsScene;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();



protected:


private slots:
    void selectRectangle();
    void selectLine();
    void selectEllipse();


private:

    RenderArea *canvas;

    QToolBox *toolBox;
    void createToolBox();


};

#endif // MAINWINDOW_H
