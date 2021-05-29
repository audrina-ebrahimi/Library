#include "choose_gender.h"
#include "ui_choose_gender.h"
#include "mainwindow.h"
#include "userdashboard.h"
#include "boydashboard.h"
choose_gender::choose_gender(QString user , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_gender)
{
    ui->setupUi(this);
    this->user = user;
}

QString choose_gender::getUser()
{
    return user;
}

choose_gender::~choose_gender()
{
    delete ui;
}

void choose_gender::on_menuButton_clicked()
{
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}

void choose_gender::on_closeButton_clicked()
{
    this->close();
}

void choose_gender::on_girl_Button_clicked()
{
    userdashboard * g_dash = new userdashboard(getUser());
    g_dash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    g_dash->show();
    this->close();
}

void choose_gender::on_boy_Button_clicked()
{
    boydashboard *b_dash = new boydashboard(getUser());
    b_dash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    b_dash->show();
    this->close();
}
