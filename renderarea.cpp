#include "renderarea.h"
#include <QtWidgets>
#include <QDebug>


RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{


    //line = NULL; //item

    setMouseTracking(true);

    startDrawing = true;
    finishDrawing = false;

}

RenderArea::~RenderArea(){

}

void RenderArea::mousePressEvent(QMouseEvent *event){

    if(startDrawing){

        pressedPoint = event->pos();
        line = new Line(pressedPoint,pressedPoint);
        linesList.push_back(line);


        startDrawing = false;
        finishDrawing = true;

    }

    else if(finishDrawing){

        update();

        startDrawing = true; //get ready to start drawing
        finishDrawing = false;
    }


}



void RenderArea::mouseMoveEvent(QMouseEvent *event){


    currentPoint = event->pos();

    if(!startDrawing && finishDrawing){
        line->setP2(currentPoint);
        update();
    }


}


void RenderArea::mouseReleaseEvent(QMouseEvent *event){

    update();
}



void RenderArea::paintEvent(QPaintEvent *event){

    QPainter painter(this);

    for(unsigned i=0; i<linesList.size(); i++){


       painter.drawLine(*linesList[i]);

    }



}
