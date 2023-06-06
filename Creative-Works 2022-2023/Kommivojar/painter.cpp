#include "painter.h"
#include "top.h"
#include "edge.h"

#include <QPainter>
#include <QPaintEvent>
#include <QtMath>

const double pi = 3.1415;
const int text_size = 24;
const int knot_R = 34;
const int arrowLength = 15;
const double arrowAngle=pi/8;

Painter::Painter()
{
    shape = QBrush(QColor(204, 92, 92));
    background = QBrush(QColor(255, 255, 255));
    textPen = QPen(QColor(114, 114, 114));
    glFont.setPixelSize(text_size);
}

void Painter::draw(QPainter *painter, QPaintEvent *event)
{
    painter->fillRect(event->rect(),background);
    painter->setBrush(shape);
    painter->setPen(textPen);
    painter->setFont(glFont);

    extern QVector <TOP> tops;
    extern QVector <EDGE> edges;
    for (int i = 0; i < tops.size(); i++)
    {
        draw_top(tops[i].x, tops[i].y, painter, QString::number(i+1));
    }
    for (int i = 0; i < edges.size(); i++)
    {
        draw_edge(edges[i].x_from, edges[i].y_from, edges[i].x_to, edges[i].y_to, painter, edges[i].weight, edges[i].type);
    }
}

void Painter::draw_top(int x, int y, QPainter *painter, QString name)
{
    painter->drawEllipse(QRectF(x - knot_R, y - knot_R, 2 * knot_R, 2 * knot_R));
    int text_x = x - knot_R / 2;
    int text_y = y - text_size / 2;
    painter->drawText(QRect(text_x, text_y, knot_R, text_size), Qt::AlignCenter, name);
}

void Painter::draw_edge(int x1, int y1, int x2, int y2, QPainter *painter, int weight, int type)
{
    double line_length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    int l_x1 = (x2 - x1) / line_length * knot_R + x1;
    int l_y1 = (y2 - y1) / line_length * knot_R + y1;
    int l_x2 = x2 - (x2 - x1) / line_length * knot_R;
    int l_y2 = y2 - (y2 - y1) / line_length * knot_R;
    painter->drawLine(l_x1, l_y1, l_x2, l_y2);
    if(type == 1)
    {
        double C;
        if (x2==l_x2 && l_y2 < y2)
        {
            C = pi * 3 / 2;
        }
        else if (x2==l_x2 && l_y2 > y2)
        {
            C = pi / 2;
        }
        else if (y2 == l_y2 && l_x2 < x2)
        {
            C = pi;
        }
        else if (y2 == l_y2 && l_x2 < x2)
        {
            C = 0;
        }
        else if (y2 < l_y2 && l_x2 < x2)
        {
            C = atan(1.0 * (y2 - l_y2) / (x2 - l_x2)) + pi;
        }
        else if (y2 > l_y2 && l_x2 < x2)
        {
            C = atan(1.0 * (y2 - l_y2) / (x2 - l_x2)) + pi;
        }
        else if (y2 < l_y2 && l_x2 > x2)
        {
            C = atan(1.0 * (y2 - l_y2) / (x2 - l_x2)) + 2 * pi;
        }
        else if (y2 > l_y2 && l_x2 > x2)
        {
            C = atan(1.0 * (y2 - l_y2) / (x2 - l_x2)) + 0;
        }
        int a_x1 = cos(C + arrowAngle) * arrowLength + l_x2;
        int a_x2 = cos(C - arrowAngle) * arrowLength + l_x2;
        int a_y1 = sin(C + arrowAngle) * arrowLength + l_y2;
        int a_y2 = sin(C - arrowAngle) * arrowLength + l_y2;
        painter->drawLine(l_x2, l_y2, a_x1, a_y1);
        painter->drawLine(l_x2, l_y2, a_x2, a_y2);
    }
    int text_x = (l_x2 + l_x1) / 2 - knot_R / 2;
    int text_y = (l_y2 + l_y1) / 2 - text_size / 2;
    painter->drawRect(QRectF(text_x, text_y, knot_R, text_size));
    painter->drawText(QRect(text_x, text_y, knot_R, text_size), Qt::AlignCenter, QString::number(weight));
}
