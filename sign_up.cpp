#include "sign_up.h"
#include "ui_sign_up.h"

sign_up::sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {border-image: url(:new/photos/bookshelves.jpg);}");
}

sign_up::~sign_up()
{
    delete ui;
}
