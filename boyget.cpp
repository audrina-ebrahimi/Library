#include "boyget.h"
#include "ui_boyget.h"

#include "boydashboard.h"
#include "returnboy.h"

#include <QFile>
#include <QCompleter>
#include <QDate>
#include <QMessageBox>

#define expire 7
boyGet::boyGet(QString user , QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boyGet)
{
    ui->setupUi(this);

    //Transfer main, dash and username
    this->qMain = main;
    this->dash = dash;
    this->user = user;

    //Fill the table
    load();
}

//Function for filling the table widget for
void boyGet::load()
{
    ui->tableWidget->setRowCount(0);

    //Read books from file and fill their map
    QFile myfile("books.txt");
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

    //Read groups from file and fill their map
    QFile file("get_return.txt");
    file.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in1(&file);

    get_return.clear();
    while(!in1.atEnd())
    {
       QStringList line = in1.readLine().split(" ");
       get_return[qMakePair(line[0],line[1])] = QDate::fromString(line[2], "yyyyMMdd");
    }

    file.close();

    //Fill table widget
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

//Close, menu and dash
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

//Get book
void boyGet::on_getButton_clicked()
{
    //Check if the member already has 5 books
    if(boydashboard :: get_book_number(user) == 5)
    {
        QMessageBox limit;
        limit.setText("You've already got 5 books in your hand.\nYou can\'t get another book\nPress \"Ok\" to go to the return form.");
        limit.setIcon(QMessageBox :: Critical);
        limit.setStandardButtons(QMessageBox::Ok);
        limit.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        limit.setDefaultButton(QMessageBox::Ok);
        limit.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        limit.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #FFA200; color: black; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #ff5400;}"

                    "QMessageBox{background-color: #FF0A0A; font:12pt Tw Cen MT Condensed Extra Bold; border: 5px solid #FF7B00;}");

        if(limit.exec())
        {
            returnBoy * ret =  new returnBoy(user , this , qMain);
            ret->setWindowFlags(Qt::Window | Qt:: FramelessWindowHint);
            ret->show();
            this->close();
        }

    }
    //Get the book
    else
    {
        //Set dates
        QDate today = QDate::currentDate();
        QDate expiration = today.addDays(expire);

        //Add to map
        QString isbn = ui->tableWidget->selectedItems()[1]->text();

        get_return.insert(qMakePair(user , isbn) , expiration);

        //Add user book to file
        QFile myfile("get_return.txt");
        myfile.open(QIODevice::Text | QIODevice :: WriteOnly);
        QTextStream out(&myfile);

        for(auto i=get_return.begin() ; i!=get_return.end() ; ++i)
            out << i.key().first << " " << i.key().second << " " << i.value().toString("yyyyMMdd") << "\n";

        myfile.close();

        //Minus 1 from availablity of book
        book[isbn][6] = QString::number(book[isbn].at(6).toInt()-1);

        QFile file("books.txt");
        file.open(QIODevice :: WriteOnly | QIODevice::Text);
        QTextStream out2(&file);
        for(auto i=book.begin() ; i != book.end() ; i++)
            out2 << i.key() << " " << i.value().join(" ") << "\n";
        file.close();

        QMessageBox success;
        success.setText("This book is successfully added to your account.");

        success.setIconPixmap(QPixmap (":/icons/icons/check.png"));
        success.setStandardButtons(QMessageBox::Ok);
        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setInformativeText("Caution! you've got this book from \"" + today.toString("yyyyMMMdd") + "\" to \"" + expiration.toString("yyyyMMMdd") +"\"");

        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #FFA200; color: black; border-radius:10px;}"

                "QPushButton:hover{ background-color: #ff5400;}"

                "QMessageBox{background-color: #FF0A0A; font:12pt Tw Cen MT Condensed Extra Bold; border: 5px solid #FF7B00;}");
        success.exec();

        load();
    }
}

//Search box
void boyGet::on_lineEdit_textChanged(const QString &arg1)
{
    //If the line edit is empty show all
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

