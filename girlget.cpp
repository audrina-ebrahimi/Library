#include "girlget.h"
#include "ui_girlget.h"

#include <boydashboard.h>
#include <returngirl.h>

#include <QFile>
#include <QDate>
#include <QMessageBox>
#include <QCompleter>

#define expire 7

girlGet::girlGet(QString user , QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::girlGet)
{
    ui->setupUi(this);

    //Transfer main, dash and username
    this->qMain = main;
    this->dash = dash;
    this->user = user;

    //Fill the table
    load();
}

//Show books in table widget and fill the maps
void girlGet::load()
{
    ui->tableWidget->setRowCount(0);

    //Read from file and fill the book map
    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&myfile);

    book.clear();
    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       book[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           book[line[0]] << line.at(i);
    }

    //Set completer for ISBNs
    QCompleter * complete = new QCompleter(book.keys() ,this);
    complete->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(complete);

    myfile.close();

    //Read from file and fill the get and return map
    QFile file("F:/Qt/Library/get_return.txt");
    file.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in1(&file);

    get_return.clear();
    while(!in1.atEnd())
    {
       QStringList line = in1.readLine().split(" ");
       get_return[qMakePair(line[0],line[1])] = QDate::fromString(line[2], "yyyyMMdd");
    }

    file.close();

    //Fill the table widget
    int j=0;
    for(auto i=book.begin() ; i != book.end() ; ++i)
    {
        if(i.value().at(6).toInt() == 0 || get_return.contains(qMakePair(user,i.key())))
            continue;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(i.value().at(0)));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(i.key()));
        for(int k=1 ; k<i.value().size() ; ++k)
            ui->tableWidget->setItem(j , k+1 , new QTableWidgetItem(i.value().at(k)));
        j++;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

//Dragable
void girlGet::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void girlGet::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

girlGet::~girlGet()
{
    delete ui;
}

//Close, menu and dash
void girlGet::on_closeButton_clicked()
{
    this->close();
}

void girlGet::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

void girlGet::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

//Get the book
void girlGet::on_getButton_clicked()
{
    //Check if the user already has 5 book
    if(boydashboard :: get_book_number(user) == 5)
    {
        QMessageBox limit;
        limit.setText("You've already got 5 books in your hand. Shame on you!!\nGet them back!!!!\nPress \"Ok\" to go to return form.");
        limit.setIcon(QMessageBox :: Critical);
        limit.setStandardButtons(QMessageBox::Ok);
        limit.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        limit.setDefaultButton(QMessageBox::Ok);
        limit.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        limit.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #00b4d8; color: black; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #0466c8;}"

                    "QMessageBox{background-color: #47e6ee; font:12pt Tw Cen MT Condensed Extra Bold; border: 5px solid blue;}");

        if(limit.exec())
        {
            returnGirl * ret =  new returnGirl(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }

    }

    //Get the book
    else
    {

        //Set get and return date
        QDate today = QDate::currentDate();
        QDate expiration = today.addDays(expire);

        //Add the book to get and return map
        QString isbn = ui->tableWidget->selectedItems()[1]->text();

        get_return.insert(qMakePair(user , isbn) , expiration);

        //Fill the file with get and return map
        QFile myfile("F:/Qt/Library/get_return.txt");
        myfile.open(QIODevice::Text | QIODevice :: WriteOnly);
        QTextStream out(&myfile);

        for(auto i=get_return.begin() ; i!=get_return.end() ; ++i)
            out << i.key().first << " " << i.key().second << " " << i.value().toString("yyyyMMdd") << "\n";

        myfile.close();

        //Minus one from the book availablity
        book[isbn][6] = QString::number(book[isbn].at(6).toInt()-1);


        //Fill the map of book
        QFile file("F:/Qt/Library/books.txt");
        file.open(QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream out2(&file);
        for(auto i=book.begin() ; i != book.end() ; i++)
            out2 << i.key() << " " << i.value().join(" ") << "\n";
        file.close();

        QMessageBox success;
        success.setText("This book successfully added to your account.");

        success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
        success.setStandardButtons(QMessageBox::Ok);
        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setInformativeText("Caution! you've got this book from \"" + today.toString("yyyyMMMdd") + "\" to \"" + expiration.toString("yyyyMMMdd") +"\"");

        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #00b4d8; color: black; border-radius:10px;}"

                "QPushButton:hover{ background-color: #0466c8;}"

                "QMessageBox{background-color: #47e6ee; font:12pt Tw Cen MT Condensed Extra Bold; border: 5px solid blue;}");
        success.exec();

        load();
    }

}

//Search text
void girlGet::on_lineEdit_textChanged(const QString &arg1)
{
    //If line edit is empty show all
    if(arg1 == "")
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            ui->tableWidget->showRow(i);
    else
    {
        for(int i=0 ; i<ui->tableWidget->rowCount() ; i++)
            ui->tableWidget->hideRow(i);

        QList <QTableWidgetItem *> all;
        all = ui->tableWidget->findItems(arg1, Qt::MatchStartsWith);

        for (int i = 0; i < all.size(); ++i)
            ui->tableWidget->showRow(all.at(i)->row());
    }
}

