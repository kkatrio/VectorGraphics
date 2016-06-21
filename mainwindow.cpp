#include "mainwindow.h"

#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow()
{


    canvas = new RenderArea;


    createToolBox();


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox,0,Qt::AlignTop);
    layout->addWidget(canvas);


    QWidget *mainWidget = new QWidget;
    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);
    resize(600,400);

}

MainWindow::~MainWindow(){

}

void MainWindow::createToolBox(){


    QToolButton *button1 = new QToolButton;
    button1->setIcon(QIcon(":/images/line.png"));
    button1->setIconSize(QSize(50,50));
    connect(button1,SIGNAL(clicked(bool)),this,SLOT(selectLine()));

    QToolButton *button2 = new QToolButton;
    button2->setIcon(QIcon(":/images/rectangle.png"));
    button2->setIconSize(QSize(50,50));
    connect(button2,SIGNAL(clicked(bool)),this,SLOT(selectRectangle()));

    QToolButton *button3 = new QToolButton;
    button3->setIcon(QIcon(":/images/circle.png"));
    button3->setIconSize(QSize(50,50));
    connect(button3,SIGNAL(clicked(bool)),this,SLOT(selectEllipse()));


    QGridLayout *shapesLayout = new QGridLayout;
    shapesLayout->addWidget(button1,0,0);
    shapesLayout->addWidget(button2,1,0);
    shapesLayout->addWidget(button3,2,0);


    QWidget *shapesWidget = new QWidget;
    shapesWidget->setLayout(shapesLayout);


    toolBox = new QToolBox;
    toolBox->addItem(shapesWidget,tr("shapes"));
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed));
    toolBox->setMinimumWidth(shapesWidget->sizeHint().width());


}

void MainWindow::selectRectangle(){

    canvas->Type = RenderArea::ShapeGeometry::RectangleG;
}

void MainWindow::selectLine(){

    canvas->Type = RenderArea::ShapeGeometry::LineG;
}

void MainWindow::selectEllipse(){

    canvas->Type = RenderArea::ShapeGeometry::EllipseG;
}
