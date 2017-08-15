#include "renderarea.h"
#include <QtWidgets>
#include <QDebug>


RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{


    //line = NULL; //item

    setMouseTracking(true);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    startDrawing = true;
    finishDrawing = false;

}

RenderArea::~RenderArea(){

}

void RenderArea::mousePressEvent(QMouseEvent *event){

    if(startDrawing){

        pressedPoint = event->pos();


        // creating objects

        if(Type == LineG){

            shape = new Line(pressedPoint,pressedPoint);
            shapesList.push_back(shape);
        }

        else if(Type == RectangleG){

            shape = new Rectangle(pressedPoint,pressedPoint);
            shapesList.push_back(shape);
        }

        else if(Type == EllipseG){

            shape = new Ellipse(pressedPoint,pressedPoint);
            shapesList.push_back(shape);
        }

        //


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

        shape->resizeShape(currentPoint);
        update();
    }


}


void RenderArea::mouseReleaseEvent(QMouseEvent *){

    update();
}



void RenderArea::paintEvent(QPaintEvent *){

    QPainter painter(this);

    for(unsigned i=0; i<shapesList.size(); i++){

        shapesList[i]->drawShape(painter); //shapesList contains pointers
    }



}
