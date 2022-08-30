#include "preedit.h"
#include "ui_preedit.h"

#include "editbook.h"

#include <QFile>

preEdit::preEdit(QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::preEdit)
{
    ui->setupUi(this);

    //Transfer main and dash
    this->qMain = main;
    this->dash = dash;

    //Fill the table widget
    load();
}

//Dragable
void preEdit::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void preEdit::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

//Fill the table widget and books map
void preEdit::load()
{
    ui->tableWidget->setRowCount(0);

    //Read from file and fill the map
    QFile myfile("books.txt");
    myfile.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&myfile);



    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       book[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           book[line[0]] << line.at(i);
    }

    //Fill the table widget
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

preEdit::~preEdit()
{
    delete ui;
}

//Close, menu and dash
void preEdit::on_closeButton_clicked()
{
    this->close();
}

void preEdit::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void preEdit::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

//Edit the book
void preEdit::on_editButton_clicked()
{
    //Seng book's ISBN to edit part
    QString isbn = ui->tableWidget->selectedItems().at(1)->text();

    editBook *edit = new editBook(isbn , dash , qMain);
    edit->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    edit->show();
    this->close();
}

