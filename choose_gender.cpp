#include "choose_gender.h"
#include "ui_choose_gender.h"
#include "mainwindow.h"
#include "userdashboard.h"
#include "boydashboard.h"
choose_gender::choose_gender(QWidget * login , QWidget * main , QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_gender)
{
    ui->setupUi(this);
    this->user = user;
    this->qMain = main;
    this->login = login;
}

void choose_gender::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void choose_gender::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

QString choose_gender::get_user()
{
  return this->user;
}


choose_gender::~choose_gender()
{
    delete ui;
}

void choose_gender::on_menuButton_clicked()
{
    main->show();
    this->close();
}

void choose_gender::on_closeButton_clicked()
{
    this->close();
}

void choose_gender::on_girl_Button_clicked()
{
    userdashboard * g_dash = new userdashboard(login , qMain , get_user());
    g_dash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    g_dash->show();
    this->close();
}

void choose_gender::on_boy_Button_clicked()
{
    boydashboard *b_dash = new boydashboard(login , qMain , get_user());
    b_dash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    b_dash->show();
    this->close();
}
