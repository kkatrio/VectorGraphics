#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QRect>


class Ellipse : public Shape, public QRect
{
public:
    Ellipse(const QPoint &p1, const QPoint &p2);

    void resizeShape(const QPoint &p2);
    void drawShape(QPainter &painter);
};

#endif // ELLIPSE_H
