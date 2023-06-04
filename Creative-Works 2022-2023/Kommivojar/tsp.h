#ifndef TSP_H
#define TSP_H

#include <QMainWindow>
#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TSP; }
QT_END_NAMESPACE

class TSP : public QMainWindow
{
    Q_OBJECT

public:
    TSP(QWidget *parent = nullptr);
    ~TSP();
    GlWidget* openGlW;

private slots:
    void on_Btn_Add_Top_clicked();

    void on_Btn_Del_Top_clicked();

    void on_Btn_Add_Edge_1_clicked();

    void on_Btn_Add_Edge_2_clicked();

    void on_Btn_Calculate_clicked();

    void on_L_Clear_clicked();

private:
    Ui::TSP *ui;

};
#endif // TSP_H
