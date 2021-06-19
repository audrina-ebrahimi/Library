#include "view_booklist.h"
#include "ui_view_booklist.h"

#include "mainwindow.h"
#include "admindashboard.h"

#include <QFile>
#include <QCompleter>

view_booklist::view_booklist(QWidget * admin , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_booklist)
{
    ui->setupUi(this);
    this->qMain = main;
    this->admin = admin;
    load();
}

void view_booklist::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void view_booklist::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

view_booklist::~view_booklist()
{
    delete ui;
}

void view_booklist::load()
{
    ui->tableWidget->setRowCount(0);
    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&myfile);



    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       book[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           book[line[0]] << line.at(i);
    }

    int j=0;
    for(auto i=book.begin() ; i != book.end() ; i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(i.value().at(0)));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(i.key()));
        for(int k=1 ; k<i.value().size() ; k++)
            ui->tableWidget->setItem(j , k+1 , new QTableWidgetItem(i.value().at(k)));
        j++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    myfile.close();
}

void view_booklist::on_closeButton_clicked()
{
    this->close();
}

void view_booklist::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void view_booklist::on_dashButton_clicked()
{
    admin->show();
    this->close();
}

void view_booklist::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 == "")
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            ui->tableWidget->showRow(i);
    else
    {
        if(ui->comboBox->currentIndex() == 0)
        {
            for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
                ui->tableWidget->hideRow(i);

            QList <QTableWidgetItem *> all;
            all = ui->tableWidget->findItems(arg1, Qt::MatchStartsWith);

            for (int i = 0; i < all.size(); ++i)
               ui->tableWidget->showRow(all.at(i)->row());
        }
        else
        {
            for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            {
                if(ui->tableWidget->item(i,ui->comboBox->currentIndex()-1)->text().startsWith(arg1 , Qt::CaseInsensitive))
                    ui->tableWidget->showRow(i);
                else
                    ui->tableWidget->hideRow(i);
            }
        }
    }
}

