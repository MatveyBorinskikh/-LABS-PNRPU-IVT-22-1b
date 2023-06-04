#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include "painter.h"

class GlWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GlWidget(QWidget *parent);
    void redraw();
    void paintEvent(QPaintEvent* event) override;

private:
   Painter* mypainter;

};

#endif // MYGLWIDGET_H
