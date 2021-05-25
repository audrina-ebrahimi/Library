#include "sign_up.h"
#include "ui_sign_up.h"
#include "mainwindow.h"
#include "log_in.h"
#include "person.h"
#include <QFile>
#include <QTextStream>
#include <overload.h>
#include <QMessageBox>
#include <QVector>
#include <QtDebug>

sign_up::sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::on_closeButton_clicked()
{
    this->close();
}

void sign_up::on_menuButton_clicked()
{
    MainWindow *main = new MainWindow;
    main->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    main->show();
    this->close();
}

void sign_up::on_sign_up_Button_clicked()
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
        if(line.contains(person.get_name() , Qt :: CaseSensitive))
        {
            QMessageBox warn;
            warn.setText("The username you chose already exsist. Please pick another one.");
            warn.setIcon(QMessageBox :: Critical);
            warn.setStandardButtons(QMessageBox::Ok);



            warn.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
            warn.setDefaultButton(QMessageBox::Ok);
            warn.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

            warn.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                               "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                               "QMessageBox{background-color: rgb(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
            warn.exec();
            ui->lineEdit_name->clear();
            ui->lineEdit_pass->clear();
            check_find = true;
            break;
       }
    }while(!line.isNull());

    myfile.close();

    if(check_find == false)
    {

        QFile file("F:\\Qt\\Library\\name_pass.txt");
        file.open(QIODevice :: Append);
        QTextStream out(&file);
        out << person;
        file.flush();
        file.close();


        QMessageBox success;
        success.setText("Thank you for signing up. Press \"OK\" to go to \"LOG IN\" form.");

        success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));


        success.setStandardButtons(QMessageBox::Ok);

        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);
        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(255, 209, 26); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: black; color: rgb(255, 209, 26);}"

                           "QMessageBox{background-color: rgb(255,183,0,0.7);font:12pt Tw Cen MT Condensed Extra Bold;}");
        if(success.exec() == QMessageBox::Ok)
        {
                log_in * log = new log_in;
                log->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                log->show();
                this->close();
        }

    }


}

