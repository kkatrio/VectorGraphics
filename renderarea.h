#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <vector>
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"
#include "shape.h"


class RenderArea : public QWidget
{

    Q_OBJECT


public:
    RenderArea(QWidget *parent = 0);
    ~RenderArea();


    enum ShapeGeometry {LineG,RectangleG,EllipseG};

    ShapeGeometry Type;


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);



private:

    Shape *shape;
    std::vector<Shape*> shapesList;


    QPoint pressedPoint;
    QPoint currentPoint;

    bool startDrawing;
    bool finishDrawing;
};

#endif // RENDERAREA_H
