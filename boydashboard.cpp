#include "boydashboard.h"
#include "ui_boydashboard.h"
#include "log_in.h"
#include "mainwindow.h"
#include "viewboy.h"
#include <QMessageBox>
#include "boyget.h"
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


void boydashboard::on_pushButton_clicked()
{
    QMessageBox success;
    success.setText("In an Islamic country? Shame on you!!\nThis item is not available in your country. Astaghfirullah!!\nPress \"Ok\" to return to Dashboard");
    success.setIcon(QMessageBox :: Information);
    success.setStandardButtons(QMessageBox::Ok);
    success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    success.setDefaultButton(QMessageBox::Ok);
    success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

    success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #4361ee; border-radius:10px;}"

                "QPushButton:hover{ background-color: #3b28cc;}"

                "QMessageBox{background-color: #48cae4; font:12pt Tw Cen MT Condensed Extra Bold;}");
    success.exec();
}


void boydashboard::on_getButton_clicked()
{
    boyGet * get = new boyGet(this , qMain);
    get->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
    get->show();
    this->close();
}

