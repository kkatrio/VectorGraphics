#include "widget.h"

#include <QMouseEvent>
#include <QPainter>


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


}



void Widget::mouseMoveEvent(QMouseEvent *event){


    currentPoint = event->pos();

    if (Proccess == startNew){

        line = new QLine(pressedPoint,pressedPoint);

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

    if (line != NULL){

        painter.drawLine(*line);
    }

}
