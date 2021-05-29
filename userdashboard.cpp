#include "userdashboard.h"
#include "ui_userdashboard.h"
#include "mainwindow.h"
#include "log_in.h"
userdashboard::userdashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userdashboard)
{
    ui->setupUi(this);
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
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}

void userdashboard::on_logoutButton_clicked()
{
    log_in *log = new log_in;
    log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    log->show();
    this->close();
}
