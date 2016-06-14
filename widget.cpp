#include "widget.h"

//#include <QMouseEvent>
//#include <QPainter>

#include <QtWidgets>
#include <QDebug>

Widget::Widget(QWidget *parent)
    :QWidget(parent)
{

    Proccess = startNew;

}

Widget::~Widget()
{

}


void Widget::mousePressEvent(QMouseEvent *event){

    pressedPoint = event->pos();

    line = NULL;
}



void Widget::mouseMoveEvent(QMouseEvent *event){


    currentPoint = event->pos();

    if (Proccess == startNew){

        line = new QLine(pressedPoint,pressedPoint);
        lines.push_back(line);

        Proccess = creating;
    }

    else if(Proccess == creating){

        line->setP2(currentPoint);

    }



    update();
}



void Widget::mouseReleaseEvent(QMouseEvent *event){


    Proccess = startNew;

    update();
}



void Widget::paintEvent(QPaintEvent *event){

    QPainter painter(this);


    for(unsigned i=0; i < lines.size(); i++){

        painter.drawLine(*lines[i]);

    }


}



