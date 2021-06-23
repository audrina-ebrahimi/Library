#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "log_in.h"
#include "sign_up.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//Dragable
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Close
void MainWindow::on_closeButton_clicked()
{
    this->close();
}

//Login
void MainWindow::on_login_Button_clicked()
{
    log_in *log = new log_in(this);
    log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    log->show();
    this->hide();

}

//Sign up
void MainWindow::on_signup_Button_clicked()
{
    sign_up * sign = new sign_up(this);
    sign->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    sign->show();
    this->hide();
}
