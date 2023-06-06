#include "secwin.h"
#include "ui_secwin.h"

SecWin::SecWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecWin)
{
    ui->setupUi(this);
}

SecWin::~SecWin()
{
    delete ui;
}
