#include "viewboy.h"
#include "ui_viewboy.h"
#include "mainwindow.h"
#include "boydashboard.h"
#include <QFile>
viewboy::viewboy(QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewboy)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
    load();
}

void viewboy::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void viewboy::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

void viewboy::load()
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
    for(auto i=book.begin() ; i != book.end() ; ++i)
    {
        if(i.value().at(6).toInt() == 0)
            continue;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(i.value().at(0)));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(i.key()));
        for(int k=1 ; k<i.value().size() ; ++k)
            ui->tableWidget->setItem(j , k+1 , new QTableWidgetItem(i.value().at(k)));
        j++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    myfile.close();
}

viewboy::~viewboy()
{
    delete ui;
}


void viewboy::on_closeButton_clicked()
{
    this->close();
}

void viewboy::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void viewboy::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

void viewboy::on_searchEdit_textChanged(const QString &arg1)
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

