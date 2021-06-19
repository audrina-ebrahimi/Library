#include "admindashboard.h"
#include "ui_admindashboard.h"

#include "mainwindow.h"
#include "log_in.h"
#include "groupbooks.h"
#include "view_booklist.h"
#include "viewmember.h"
#include "addbook.h"
#include "preedit.h"
#include "deletebook.h"
#include "situation.h"

admindashboard::admindashboard(QWidget * login , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admindashboard)
{
    ui->setupUi(this);
    this->qMain = main;
    this->login = login;
}

void admindashboard::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void admindashboard::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

admindashboard::~admindashboard()
{
    delete ui;
}

void admindashboard::on_closeButton_clicked()
{
    this->close();
}

void admindashboard::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void admindashboard::on_logoutButton_clicked()
{
    login->show();
    this->close();
}

void admindashboard::on_groupButton_clicked()
{
    GroupBooks *group = new GroupBooks(this , qMain);
    group->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    group->show();
    this->hide();

}

void admindashboard::on_viewBookButton_clicked()
{
    view_booklist *list = new view_booklist(this , qMain);
    list->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    list->show();
    this->hide();
}

void admindashboard::on_viewMemButton_clicked()
{
    viewMember *member = new viewMember(this , qMain);
    member->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    member->show();
    this->hide();
}

void admindashboard::on_addButton_clicked()
{
    addBook * add = new addBook(this , qMain);
    add->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    add->show();
    this->hide();

}

void admindashboard::on_editButton_clicked()
{
    preEdit *pre = new preEdit(this , qMain);
    pre->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pre->show();
    this->hide();
}

void admindashboard::on_deleteButton_clicked()
{
    deleteBook * deleteB = new deleteBook(this , qMain);
    deleteB->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    deleteB->show();
    this->hide();
}

void admindashboard::on_situationButton_clicked()
{
    situation * condition = new situation(this , qMain);
    condition->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    condition->show();
    this->hide();
}

