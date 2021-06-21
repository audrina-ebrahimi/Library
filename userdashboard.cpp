#include "userdashboard.h"
#include "ui_userdashboard.h"

#include "mainwindow.h"
#include "viewgirl.h"
#include "girlget.h"
#include "returngirl.h"
#include "closegirl.h"
#include "boydashboard.h"

#include <QMessageBox>
#include <QFile>
#include <QDate>

userdashboard::userdashboard(QWidget * main , QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userdashboard)
{
    ui->setupUi(this);

    //Transfer main and username
    this->user = user;
    this->qMain = main;
}

//Dragable
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

//Function for checking expired book
bool userdashboard::expired()
{
    //Read get and return file and fill its map
    QFile file("get_return.txt");
    file.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&file);

    get_return.clear();
    while(!in.atEnd())
    {
        QStringList line = in.readLine().split(" ");
        get_return[qMakePair(line[0],line[1])] = QDate::fromString(line[2], "yyyyMMdd");
    }
    file.close();

    //Return true::expired  false::unexpired
    for(auto i=get_return.begin() ; i != get_return.end() ; ++i)
        if(i.key().first == user)
        {
            QDate current = QDate:: currentDate();
            int d = current.daysTo(i.value());
            if(d<0)
                return true;
        }
    return false;

}

userdashboard::~userdashboard()
{
    delete ui;
}

//Close, menu and log out
void userdashboard::on_closeButton_clicked()
{
    this->close();
    expired();
}

void userdashboard::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void userdashboard::on_logoutButton_clicked()
{
    closeGirl * close = new closeGirl(qMain);
    close->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    close->show();
    this->close();
}

//Show the book list
void userdashboard::on_listButton_clicked()
{
    //If user has expired book
    if(expired())
    {
        QMessageBox expiration;
        expiration.setText("You can't get another book or do anything until returning the expired book you've got! Shame on you!!\nReturn this ASAP!\nPress \"Ok\" to go to return form.");
        expiration.setIcon(QMessageBox :: Critical);
        expiration.setStandardButtons(QMessageBox::Ok);
        expiration.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        expiration.setDefaultButton(QMessageBox::Ok);
        expiration.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        expiration.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #9B15F4; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #b5179e;}"

                    "QMessageBox{background-color: #deaaff; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid purple;}");
        if(expiration.exec())
        {
            returnGirl * ret =  new returnGirl(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }
    }
    else
    {
        viewgirl * view = new viewgirl(this , qMain);
        view->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        view->show();
        this->close();
    }

}

//Private room
void userdashboard::on_pushButton_clicked()
{
    QMessageBox success;
    success.setText("In an Islamic country? Shame on you!!\nThis item is not available in your country. Astaghfirullah!!\nPress \"Ok\" to return to Dashboard");
    success.setIcon(QMessageBox :: Critical);
    success.setStandardButtons(QMessageBox::Ok);
    success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    success.setDefaultButton(QMessageBox::Ok);
    success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

    success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #9B15F4; border-radius:10px;}"

                "QPushButton:hover{ background-color: #b5179e;}"

                "QMessageBox{background-color: #deaaff; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid purple;}");
    success.exec();

}

//Get book
void userdashboard::on_getButton_clicked()
{
    //If the user alreagy got five book
    if(boydashboard :: get_book_number(user) == 5)
    {
        QMessageBox limit;
        limit.setText("You've already got 5 books in your hand. Shame on you!!\nGet them back!!!!\nPress \"Ok\" to go to return form.");
        limit.setIcon(QMessageBox :: Critical);
        limit.setStandardButtons(QMessageBox::Ok);
        limit.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        limit.setDefaultButton(QMessageBox::Ok);
        limit.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        limit.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #9B15F4; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #b5179e;}"

                    "QMessageBox{background-color: #deaaff; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid purple;}");

        if(limit.exec())
        {
            returnGirl * ret =  new returnGirl(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }
    }

    //If user has expired book
    else if(expired())
    {
        QMessageBox expiration;
        expiration.setText("You can't get another book or do anything until returning the expired book you've got! Shame on you!!\nReturn this ASAP!\nPress \"Ok\" to go to return form.");
        expiration.setIcon(QMessageBox :: Critical);
        expiration.setStandardButtons(QMessageBox::Ok);
        expiration.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        expiration.setDefaultButton(QMessageBox::Ok);
        expiration.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        expiration.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #9B15F4; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #b5179e;}"

                    "QMessageBox{background-color: #deaaff; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid purple;}");
        if(expiration.exec())
        {
            returnGirl * ret =  new returnGirl(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }
    }
    else
    {
        girlGet * get = new girlGet(user , this , qMain);
        get->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
        get->show();
        this->close();
    }

}

//Return book
void userdashboard::on_returnButton_clicked()
{
    returnGirl *ret = new returnGirl(user , this , qMain);
    ret->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ret->show();
    this->close();
}

