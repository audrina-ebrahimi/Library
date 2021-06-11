#include "returnboy.h"
#include "ui_returnboy.h"

returnBoy::returnBoy(QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::returnBoy)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
}
void returnBoy::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void returnBoy::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}
returnBoy::~returnBoy()
{
    delete ui;
}

void returnBoy::on_closeButton_clicked()
{
    this->close();
}


void returnBoy::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}


void returnBoy::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

