#ifndef MULTI_H
#define MULTI_H

#include <QWidget>

namespace Ui {
class Multi;
}

class Multi : public QWidget
{
    Q_OBJECT

public:
    explicit Multi(QWidget *parent = nullptr);
    ~Multi();

private:
    Ui::Multi *ui;
};

#endif // MULTI_H
