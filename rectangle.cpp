#include "rectangle.h"

Rectangle::Rectangle(const QPoint &p1,const QPoint &p2) : QRect(p1,p2)
{

}

void Rectangle::resizeShape(const QPoint &p2){

    setBottomRight(p2);

}

void Rectangle::drawShape(QPainter &painter){

    painter.drawRect(*this);
}
