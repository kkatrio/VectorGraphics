#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "line.h"
#include <vector>

class RenderArea : public QWidget
{

    Q_OBJECT


public:
    RenderArea(QWidget *parent = 0);
    ~RenderArea();



protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);



private:

    Line *line;

    QPoint pressedPoint;
    QPoint currentPoint;

    std::vector<Line*> linesList;

    bool startDrawing;
    bool finishDrawing;
};

#endif // RENDERAREA_H
