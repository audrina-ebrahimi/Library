#include "editbook.h"
#include "ui_editbook.h"

#include <QMessageBox>
#include <QFile>

editBook::editBook(QString isbn , QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editBook)
{
    ui->setupUi(this);

    //Transfer main, dash and ISBN
    this->qMain = main;
    this->dash = dash;
    this->isbn = isbn;


    //Read books from file and fill their map
    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice :: ReadOnly);
    QTextStream in(&myfile);



    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       book[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           book[line[0]] << line.at(i);
    }

    //Fill items with the book's information
    ui->ISBNEdit->setText(isbn);
    ui->nameEdit->setText(book[isbn].at(0));
    ui->authorEdit->setText(book[isbn].at(1));
    ui->subjectEdit->setText(book[isbn].at(2));
    ui->publisherEdit->setText(book[isbn].at(3));
    ui->languageEdit->setText(book[isbn].at(4));
    ui->spinPage->setValue(book[isbn].at(5).toInt());
    ui->spinAvail->setValue(book[isbn].at(6).toInt());

    //Remove the book for edit
    book.remove(isbn);

    myfile.close();


}

//Dragable
void editBook::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void editBook::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

editBook::~editBook()
{
    delete ui;
}

//Close, menu and dash
void editBook::on_closeButton_clicked()
{
    this->close();
}

void editBook::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void editBook::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

//Edit the book
void editBook::on_pushButton_clicked()
{
    //Get book's new informarion
    isbn = ui->ISBNEdit->text();
    book[isbn] << ui->nameEdit->text() << ui->authorEdit->text() << ui->subjectEdit->text() << ui->publisherEdit->text()
               << ui->languageEdit->text() << ui->spinPage->text() << ui->spinAvail->text();

    //Fill the book file
    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice :: WriteOnly | QIODevice::Text);
    QTextStream out(&myfile);
    for(auto i=book.begin() ; i != book.end() ; i++)
        out << i.key() << " " << i.value().join(" ") << "\n";

    QMessageBox success;
    success.setText("The book has successfully edited. Press \"Ok\" to return to Dashboard");
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


