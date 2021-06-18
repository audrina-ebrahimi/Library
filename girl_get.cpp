#include "girl_get.h"


girl_get::girl_get(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::girl_get)
{
    ui->setupUi(this);
}

girl_get::~girl_get()
{
    delete ui;
}
