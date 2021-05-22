#include "log_in.h"
#include "ui_log_in.h"

log_in::log_in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {border-image: url(:new/photos/gates.jpg);}");
}

log_in::~log_in()
{
    delete ui;
}
