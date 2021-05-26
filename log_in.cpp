#include "log_in.h"
#include "ui_log_in.h"
#include "mainwindow.h"
#include "person.h"
#include <QMessageBox>
#include "overload.h"
#include "sign_up.h"
#include "choose_gender.h"
log_in::log_in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
}

log_in::~log_in()
{
    delete ui;
}

void log_in::on_closeButton_clicked()
{
    this->close();
}

void log_in::on_menuButton_clicked()
{
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}

void log_in::on_log_in_Button_clicked()
{
    Person person;
    person.set_name( ui->lineEdit_name->text() );
    person.set_pass( ui->lineEdit_pass->text() );


    QFile myfile("F:\\Qt\\Library\\name_pass.txt");
    myfile.open(QIODevice :: ReadOnly);
    QTextStream in(&myfile);
    QString line;
    bool check_find = false;

    do
    {
        line = in.readLine();
        if(line.contains(person.get_name() , Qt :: CaseSensitive) && line.contains(person.get_pass() , Qt :: CaseSensitive))
        {
            choose_gender * choose = new choose_gender;
            choose->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            choose->show();
            this->close();
            check_find = true;
            break;
        }
        else if(line.contains(person.get_name() , Qt :: CaseSensitive))
        {
            QMessageBox warn;
            warn.setText("The password you you entered is wrong.");
            warn.setIcon(QMessageBox :: Critical);
            warn.setStandardButtons(QMessageBox::Ok);



            warn.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            warn.setDefaultButton(QMessageBox::Ok);
            warn.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

            warn.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                               "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                               "QMessageBox{background-color: rgb(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
            warn.exec();
            ui->lineEdit_pass->clear();
            check_find = true;
            break;
        }
    }while(!line.isNull());

    myfile.close();

    if(check_find == false)
    {

        QMessageBox failed;
        failed.setText("Couldn't find the username you entered. Press \"OK\" to go to \"SIGN UP\" form.");

        failed.setIcon(QMessageBox :: Critical);
        failed.setStandardButtons(QMessageBox::Ok);
        failed.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        failed.setDefaultButton(QMessageBox::Ok);
        failed.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);
        failed.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                           "QMessageBox{background-color: rgb(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
        if(failed.exec() == QMessageBox::Ok)
        {
                sign_up * sign = new sign_up;
                sign->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                sign->show();
                this->close();
        }

    }

}
