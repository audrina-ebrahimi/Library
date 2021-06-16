#include "boydashboard.h"
#include "ui_boydashboard.h"

#include "mainwindow.h"
#include "viewboy.h"
#include <QMessageBox>
#include "boyget.h"
#include "returnboy.h"
#include "closeboy.h"
#include <QFile>
boydashboard::boydashboard(QWidget * main , QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boydashboard)
{
    ui->setupUi(this);
    this->user = user;
    this->qMain = main;

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

int boydashboard::get_book_number(QString user)
{
    QFile myfile("F:/Qt/Library/get_return.txt");
    myfile.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&myfile);

    int count = 0;

    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       if(line[0] == user)
           count++;
    }

    return count;
}


boydashboard::~boydashboard()
{
    delete ui;
}

void boydashboard::on_logoutButton_clicked()
{   
    closeBoy *close = new closeBoy(qMain);
    close->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
    close->show();
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

    if(get_book_number(user) == 5)
    {
        QMessageBox limit;
        limit.setText("You've already got 5 books in your hand. Shame on you!!\nGet them back!!!!\nPress \"Ok\" to go to return form.");
        limit.setIcon(QMessageBox :: Critical);
        limit.setStandardButtons(QMessageBox::Ok);
        limit.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        limit.setDefaultButton(QMessageBox::Ok);
        limit.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        limit.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #057ef0; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #3b28cc;}"

                    "QMessageBox{background-color: #48cae4; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid blue;}");

        if(limit.exec())
        {
            returnBoy * ret =  new returnBoy(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }
    }

    else
    {
        boyGet * get = new boyGet(user , this , qMain);
        get->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
        get->show();
        this->close();
    }
}


void boydashboard::on_returnButton_clicked()
{
    returnBoy * ret =  new returnBoy(user , this , qMain);
    ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
    ret->show();
    this->close();
}

