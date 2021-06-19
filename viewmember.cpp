#include "viewmember.h"
#include "ui_viewmember.h"

#include "mainwindow.h"
#include "admindashboard.h"

#include <QFile>
#include <QMessageBox>
#include <QCompleter>

viewMember::viewMember(QWidget * admin , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewMember)
{
    ui->setupUi(this);
    this->qMain = main;
    this->admin = admin;
    update();
}

void viewMember::update()
{
    ui->tableWidget->setRowCount(0);
    QFile myfile("F:/Qt/Library/name_pass.txt");
    myfile.open(QIODevice :: ReadOnly);
    QTextStream in(&myfile);



    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       user_pass[line[0]] = line[1];
    }

    QCompleter * complete = new QCompleter(user_pass.keys(),this);
    complete->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(complete);


    int j=0;
    for(auto i=user_pass.begin() ; i != user_pass.end() ; i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(i.key()));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(i.value()));
        j++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    myfile.close();
}

void viewMember::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void viewMember::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

viewMember::~viewMember()
{
    delete ui;
}

void viewMember::on_closeButton_clicked()
{
    this->close();
}

void viewMember::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void viewMember::on_dashButton_clicked()
{
    admin->show();
    this->close();
}

void viewMember::on_deleteButton_clicked()
{
    QString hated = ui->tableWidget->selectedItems()[0]->text();
    if(hated == "admin")
    {
        QMessageBox warn;
        warn.setText("Detective Dush! You are just about to delete yourself \"OSKOL!\" :/");
        warn.setIcon(QMessageBox :: Critical);
        warn.setStandardButtons(QMessageBox::Ok);



        warn.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        warn.setDefaultButton(QMessageBox::Ok);
        warn.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        warn.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(196,255,3); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: rgb(0, 255, 0);}"

                           "QMessageBox{background-color: rgba(85, 170, 0 , 0.7); font:12pt Tw Cen MT Condensed Extra Bold;}");
        warn.exec();
        return;
    }
    user_pass.remove(hated);

    QFile myfile("F:/Qt/Library/name_pass.txt");
    myfile.open(QIODevice :: WriteOnly);
    QTextStream out(&myfile);

    for(auto i = user_pass.begin() ; i != user_pass.end() ; i++)
        out << i.key() << " " << i.value() << "\n";

    update();
}

void viewMember::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == "")
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            ui->tableWidget->showRow(i);
    else
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
        {
            if(ui->tableWidget->item(i,0)->text().startsWith(arg1 , Qt::CaseInsensitive))
                ui->tableWidget->showRow(i);
            else
                ui->tableWidget->hideRow(i);
        }
}

