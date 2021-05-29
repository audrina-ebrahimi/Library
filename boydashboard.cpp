#include "boydashboard.h"
#include "ui_boydashboard.h"
#include "log_in.h"
#include "mainwindow.h"
boydashboard::boydashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boydashboard)
{
    ui->setupUi(this);
}

boydashboard::~boydashboard()
{
    delete ui;
}

void boydashboard::on_logoutButton_clicked()
{
    log_in *log = new log_in;
    log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    log->show();
    this->close();
}

void boydashboard::on_closeButton_clicked()
{
    this->close();
}

void boydashboard::on_menuButton_clicked()
{
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}
