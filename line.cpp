#include "line.h"

#include <QPainter>

Line::Line(const QPoint &p1, const QPoint &p2) : QLine(p1,p2){

}

void Line::resizeShape(const QPoint &p2){

    setP2(p2);
}

void Line::drawShape(QPainter &painter)
{
    painter.drawLine(*this);
}
