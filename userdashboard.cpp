#include "userdashboard.h"
#include "ui_userdashboard.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "log_in.h"
#include "viewgirl.h"
userdashboard::userdashboard(QWidget * login , QWidget * main , QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userdashboard)
{
    ui->setupUi(this);
    this->user = user;
    this->qMain = main;
    this->login = login;
}

void userdashboard::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void userdashboard::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

QString userdashboard::get_user()
{
    return this->user;
}


userdashboard::~userdashboard()
{
    delete ui;
}

void userdashboard::on_closeButton_clicked()
{
    this->close();
}

void userdashboard::on_menuButton_clicked()
{
    main->show();
    this->close();
}

void userdashboard::on_logoutButton_clicked()
{
    login->show();
    this->close();
}

void userdashboard::on_listButton_clicked()
{
    viewgirl * view = new viewgirl(this , qMain);
    view->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    view->show();
    this->close();

}

