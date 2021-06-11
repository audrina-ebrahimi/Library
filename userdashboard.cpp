#include "userdashboard.h"
#include "ui_userdashboard.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "log_in.h"
#include "viewgirl.h"
#include <QMessageBox>
#include "girlget.h"
#include "returngirl.h"
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
    qMain->show();
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


void userdashboard::on_pushButton_clicked()
{
    QMessageBox success;
    success.setText("In an Islamic country? Shame on you!!\nThis item is not available in your country. Astaghfirullah!!\nPress \"Ok\" to return to Dashboard");
    success.setIcon(QMessageBox :: Information);
    success.setStandardButtons(QMessageBox::Ok);
    success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    success.setDefaultButton(QMessageBox::Ok);
    success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

    success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #9B15F4; border-radius:10px;}"

                "QPushButton:hover{ background-color: #b5179e;}"

                "QMessageBox{background-color: #deaaff; font:12pt Tw Cen MT Condensed Extra Bold;}");
    success.exec();

}


void userdashboard::on_getButton_clicked()
{
    girlGet * get = new girlGet(this , qMain);
    get->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    get->show();
    this->close();

}


void userdashboard::on_returnButton_clicked()
{
    returnGirl *ret = new returnGirl(this , qMain);
    ret->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ret->show();
    this->close();
}

