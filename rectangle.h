#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QRect>
#include "shape.h"

class Rectangle : public Shape, public QRect
{
public:
    Rectangle(const QPoint &p1,const QPoint &p2);


    void resizeShape(const QPoint &p2);
    void drawShape(QPainter &painter);
};

#endif // RECTANGLE_H
