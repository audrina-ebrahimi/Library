#include "boydashboard.h"
#include "ui_boydashboard.h"
#include "log_in.h"
#include "mainwindow.h"
#include "viewboy.h"
boydashboard::boydashboard(QWidget * login , QWidget * main , QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boydashboard)
{
    ui->setupUi(this);
    this->user = user;
    this->qMain = main;
    this->login = login;
}

void boydashboard::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void boydashboard::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

QString boydashboard::get_user()
{
    return this->user;
}


boydashboard::~boydashboard()
{
    delete ui;
}

void boydashboard::on_logoutButton_clicked()
{   
    login->show();
    this->close();
}

void boydashboard::on_closeButton_clicked()
{
    this->close();
}

void boydashboard::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void boydashboard::on_listButton_clicked()
{
    viewboy *view = new viewboy(this , qMain);
    view->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
    view->show();
    this->close();
}

