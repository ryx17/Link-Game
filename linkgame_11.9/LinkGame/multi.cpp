#include "multi.h"
#include "ui_multi.h"

Multi::Multi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multi)
{
    ui->setupUi(this);
}

Multi::~Multi()
{
    delete ui;
}
