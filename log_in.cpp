#include "log_in.h"
#include "ui_log_in.h"
#include "mainwindow.h"
#include "person.h"
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

}
