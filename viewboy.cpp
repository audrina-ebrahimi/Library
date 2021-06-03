#include "viewboy.h"
#include "ui_viewboy.h"
#include "mainwindow.h"
#include "boydashboard.h"

viewboy::viewboy(QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewboy)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
}

void viewboy::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void viewboy::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}



viewboy::~viewboy()
{
    delete ui;
}


void viewboy::on_closeButton_clicked()
{
    this->close();
}

void viewboy::on_menuButton_clicked()
{
    main->show();
    this->close();
}

void viewboy::on_dashButton_clicked()
{
    dash->show();
    this->close();
}
