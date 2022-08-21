#include "sign_up.h"
#include "ui_sign_up.h"

#include "mainwindow.h"
#include "log_in.h"
#include "person.h"
#include "overload.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

sign_up::sign_up(QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);

    //Transfer main
    this->qMain = main;
}

//Dragable
void sign_up::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void sign_up::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

sign_up::~sign_up()
{
    delete ui;
}

//Close and menu
void sign_up::on_closeButton_clicked()
{
    this->close();
}

void sign_up::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

//Sign up
void sign_up::on_sign_up_Button_clicked()
{
    //Complete person class
    Person person;
    person.set_name( ui->lineEdit_name->text() );
    person.set_pass( ui->lineEdit_pass->text() );


    //Read file
    QFile myfile("name_pass.txt");
    myfile.open(QIODevice :: ReadOnly);
    QTextStream in(&myfile);
    QString line;
    bool check_find = false;

    do
    {
        line = in.readLine();

        //If the username already exists
        if(line.contains(person.get_name() , Qt :: CaseSensitive))
        {
            QMessageBox warn;
            warn.setText("The username you chose already exsists. Please pick another one.");
            warn.setIcon(QMessageBox :: Critical);
            warn.setStandardButtons(QMessageBox::Ok);



            warn.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            warn.setDefaultButton(QMessageBox::Ok);
            warn.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

            warn.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px; }"

                               "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                               "QMessageBox{background-color: rgba(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
            warn.exec();
            ui->lineEdit_name->clear();
            ui->lineEdit_pass->clear();
            check_find = true;
            break;
       }
    }while(!line.isNull());

    myfile.close();

    //If the username was unique
    if(check_find == false)
    {

        //Add user to file
        QFile file("name_pass.txt");
        file.open(QIODevice :: Append);
        QTextStream out(&file);
        out << person;
        file.flush();
        file.close();


        QMessageBox success;
        success.setText("Thank you for signing up. Press \"OK\" to go to \"Login\" form.");

        success.setIconPixmap(QPixmap (":/icons/icons/check.png"));


        success.setStandardButtons(QMessageBox::Ok);

        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);
        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                           "QMessageBox{background-color: rgba(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
        if(success.exec() == QMessageBox::Ok)
        {
                log_in * log = new log_in(qMain);
                log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                log->show();
                this->close();
        }

    }


}

