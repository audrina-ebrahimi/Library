#include "choose_gender.h"
#include "ui_choose_gender.h"
#include "mainwindow.h"
#include "userdashboard.h"
choose_gender::choose_gender(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_gender)
{
    ui->setupUi(this);
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
    userdashboard * g_dash = new userdashboard;
    g_dash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    g_dash->show();
    this->close();
}
