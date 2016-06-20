#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint> // or class
#include <QPainter>


class Shape
{
public:

    virtual void resizeShape(const QPoint &p2) = 0;
    virtual void drawShape(QPainter &painter) = 0;

};

#endif // SHAPE_H
