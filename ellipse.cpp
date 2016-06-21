#include "ellipse.h"

Ellipse::Ellipse(const QPoint &p1, const QPoint &p2) : QRect(p1,p2)
{

}

void Ellipse::drawShape(QPainter &painter){

    painter.drawEllipse(*this);
}

void Ellipse::resizeShape(const QPoint &p2){

    setBottomRight(p2);
}
