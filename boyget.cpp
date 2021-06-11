#include "boyget.h"
#include "ui_boyget.h"
#include <QFile>
boyGet::boyGet(QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boyGet)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
    load();
}

void boyGet::load()
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

void boyGet::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void boyGet::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

boyGet::~boyGet()
{
    delete ui;
}

void boyGet::on_closeButton_clicked()
{
    this->close();
}


void boyGet::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}


void boyGet::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

