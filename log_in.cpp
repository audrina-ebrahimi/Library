#include "log_in.h"
#include "ui_log_in.h"

#include "mainwindow.h"
#include "person.h"
#include "overload.h"
#include "sign_up.h"
#include "choose_gender.h"
#include "admindashboard.h"

#include <QMessageBox>

log_in::log_in( QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);

    //Transfer main
    this->qMain = main;

}

//Dragable
void log_in::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void log_in::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

log_in::~log_in()
{
    delete ui;
}

//Close and menu
void log_in::on_closeButton_clicked()
{
    this->close();
}

void log_in::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

//Login button
void log_in::on_log_in_Button_clicked()
{
    //Complete person class
    Person person;
    person.set_name( ui->lineEdit_name->text() );
    person.set_pass( ui->lineEdit_pass->text() );


    QFile myfile("name_pass.txt");
    myfile.open(QIODevice :: ReadOnly);
    QTextStream in(&myfile);
    QString line;
    bool check_find = false;

    do
    {
        line = in.readLine();
        //If user and pass exists
        if(line.contains(person.get_name() , Qt :: CaseSensitive) && line.contains(person.get_pass() , Qt :: CaseSensitive))
        {
            //If it was admin
            if(person.get_name() == "admin" && person.get_pass() == "admin")
            {
                admindashboard *admin = new admindashboard(this , qMain);
                admin->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                admin->show();
                this->close();
                ui->lineEdit_pass->clear();
                ui->lineEdit_name->clear();
                check_find = true;
                break;
            }
            //If it was usual user
            choose_gender * choose = new choose_gender(qMain , person.get_name());
            choose->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            choose->show();
            this->close();
            ui->lineEdit_pass->clear();
            ui->lineEdit_name->clear();
            check_find = true;
            break;
        }
        //If the password was wrong
        else if(line.contains(person.get_name() , Qt :: CaseSensitive))
        {
            QMessageBox warn;
            warn.setText("The password you entered is wrong.");
            warn.setIcon(QMessageBox :: Critical);
            warn.setStandardButtons(QMessageBox::Ok);



            warn.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            warn.setDefaultButton(QMessageBox::Ok);
            warn.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

            warn.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                               "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                               "QMessageBox{background-color: rgba(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
            warn.exec();
            ui->lineEdit_pass->clear();
            check_find = true;
            break;
        }
    }while(!line.isNull());

    myfile.close();

    //If the username was unavailable send user to sign up
    if(check_find == false)
    {

        QMessageBox failed;
        failed.setText("Couldn't find the username you entered. Press \"OK\" to go to the \"Signup\" form.");

        failed.setIcon(QMessageBox :: Critical);
        failed.setStandardButtons(QMessageBox::Ok);
        failed.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        failed.setDefaultButton(QMessageBox::Ok);
        failed.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);
        failed.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                           "QMessageBox{background-color: rgba(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
        if(failed.exec() == QMessageBox::Ok)
        {
                sign_up * sign = new sign_up(qMain);
                sign->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                sign->show();
                this->close();
        }

    }

}
