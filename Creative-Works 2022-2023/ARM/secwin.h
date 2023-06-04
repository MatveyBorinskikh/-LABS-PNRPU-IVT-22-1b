#ifndef SECWIN_H
#define SECWIN_H

#include <QDialog>

namespace Ui {
class SecWin;
}

class SecWin : public QDialog
{
    Q_OBJECT

public:
    explicit SecWin(QWidget *parent = nullptr);
    ~SecWin();

private:
    Ui::SecWin *ui;
};

#endif // SECWIN_H
