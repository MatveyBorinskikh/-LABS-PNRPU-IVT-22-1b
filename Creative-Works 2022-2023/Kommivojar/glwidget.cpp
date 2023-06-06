#include "glwidget.h"
#include "top.h"
#include "edge.h"

#include <QPainter>

extern QVector<TOP> tops;
extern QVector<EDGE> edges;

GlWidget::GlWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mypainter=new Painter;
}

void GlWidget::redraw()
{
   this->update();
}

void GlWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mypainter->draw(&painter,event);
    painter.end();
}
