#include "mainwindow.h"

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow()
{


    RenderArea *canvas = new RenderArea;



    setCentralWidget(canvas);
    resize(600,400);

}

MainWindow::~MainWindow(){

}



