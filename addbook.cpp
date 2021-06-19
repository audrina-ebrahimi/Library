#include "addbook.h"
#include "ui_addbook.h"

#include "book.h"
#include "overload.h"
#include "editbook.h"

#include <QFile>
#include <QMessageBox>

addBook::addBook(QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addBook)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
}

void addBook::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void addBook::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

addBook::~addBook()
{
    delete ui;
}

void addBook::on_closeButton_clicked()
{
    this->close();
}

void addBook::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void addBook::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

void addBook::on_addButton_clicked()
{
    book books(ui->nameEdit->text() , ui->authorEdit->text() , ui->subjectEdit->text() , ui->publisherEdit->text() ,
               ui->ISBNEdit->text() , ui->languageEdit->text() , ui->spinPage->value() , ui->spinAvail->value());

    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice :: ReadWrite);
    QTextStream in(&myfile);
    QString line;

    bool find = false;

    while(!in.atEnd())
    {
       line = in.readLine();
       if(line.contains(books.get_ISBN() , Qt :: CaseSensitive))
       {
           QMessageBox found;

           found.setText("The book you wanted to add already exists.\nPress \"Yes\" if you want to edit the book.\nPress \"Reset\" to add a new book.");
           found.setIcon(QMessageBox :: Critical);
           found.setStandardButtons(QMessageBox::Yes | QMessageBox::Reset);
           found.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
           found.setDefaultButton(QMessageBox::Yes);
           found.button(QMessageBox::Yes)->setCursor(Qt::PointingHandCursor);
           found.button(QMessageBox::Reset)->setCursor(Qt::PointingHandCursor);

           found.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(196,255,3); color: black; border-radius:10px;}"

                           "QPushButton:hover{ background-color: rgb(0, 255, 0);}"

                           "QMessageBox{background-color: rgba(85, 170, 0 , 0.7); font:12pt Tw Cen MT Condensed Extra Bold;}");
           int ret = found.exec();
           find = true;
           if(ret == QMessageBox::Yes)
           {
               editBook * edit = new editBook(ui->ISBNEdit->text() , dash , qMain);
               edit->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
               edit->show();
               this->close();
               break;
           }
           else if(ret == QMessageBox::Reset)
           {
               ui->nameEdit->clear();
               ui->authorEdit->clear();
               ui->subjectEdit->clear();
               ui->publisherEdit->clear();
               ui->ISBNEdit->clear();
               ui->languageEdit->clear();
               ui->spinPage->clear();
               ui->spinAvail->clear();
               break;
           }

       }
    }

    if(find == false)
    {
        QTextStream out(&myfile);
        out << books;
        myfile.close();
        QMessageBox success;

        success.setText("The book has successfully added. Press \"Ok\" to return to Dashboard");
        success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
        success.setStandardButtons(QMessageBox::Ok);
        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(196,255,3); color: black; border-radius:10px;}"

                    "QPushButton:hover{ background-color: rgb(0, 255, 0);}"

                    "QMessageBox{background-color: rgba(85, 170, 0 , 0.7); font:12pt Tw Cen MT Condensed Extra Bold;}");
        success.exec();
        dash->show();
        this->close();
    }

}

