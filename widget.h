#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <vector>

//#include "line.h"

class QGraphicsScene;
class QGraphicsView;




class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    enum ActionType {startNew, creating};

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

    std::vector<QLine*> lines;


};

#endif // WIDGET_H
