#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Painter
{
public:
    Painter();

public:
    void draw(QPainter* painter, QPaintEvent* event);
    void draw_top(int x, int y, QPainter* painter, QString name);
    void draw_edge(int x1, int y1, int x2,int y2, QPainter* painter, int weight, int type);
    QBrush shape;

private:
    QBrush background;
    QPen textPen;
    QFont glFont;
};

#endif // MYPAINTER_H
