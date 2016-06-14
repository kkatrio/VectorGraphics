#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

//#include "line.h"


enum ActionType {startNew, creating};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    ActionType Proccess;

private:

    QPoint pressedPoint;
    QPoint currentPoint;

    QLine *line;

};

#endif // WIDGET_H
