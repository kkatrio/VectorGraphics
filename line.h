#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include <QLine>
#include "shape.h"

class Line : public Shape, public QLine
{
public:

    Line(const QPoint &p1,const QPoint &p2);


    void resizeShape(const QPoint &p2);
    void drawShape(QPainter &painter);



private:



};

#endif // LINE_H
