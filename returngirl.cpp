#include "returngirl.h"
#include "ui_returngirl.h"

returnGirl::returnGirl(QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::returnGirl)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
}
void returnGirl::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void returnGirl::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}
returnGirl::~returnGirl()
{
    delete ui;
}

void returnGirl::on_closeButton_clicked()
{
    this->close();
}


void returnGirl::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}


void returnGirl::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

