#include "admindashboard.h"
#include "ui_admindashboard.h"
#include "mainwindow.h"
#include "log_in.h"
admindashboard::admindashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admindashboard)
{
    ui->setupUi(this);
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
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}

void admindashboard::on_logoutButton_clicked()
{
    log_in *log = new log_in;
    log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    log->show();
    this->close();
}
