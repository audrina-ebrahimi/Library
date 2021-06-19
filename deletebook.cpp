#include "deletebook.h"
#include "ui_deletebook.h"

#include <QMessageBox>
#include <QFile>

deleteBook::deleteBook(QWidget * dash , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deleteBook)
{
    ui->setupUi(this);
    this->qMain = main;
    this->dash = dash;
    load();
}

void deleteBook::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void deleteBook::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

void deleteBook::load()
{
    ui->tableWidget->setRowCount(0);
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

deleteBook::~deleteBook()
{
    delete ui;
}

void deleteBook::on_closeButton_clicked()
{
    this->close();
}

void deleteBook::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void deleteBook::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

void deleteBook::on_deleteButton_clicked()
{
    QString deleteBook = ui->tableWidget->selectedItems()[1]->text();

    book.remove(deleteBook);

    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice :: WriteOnly | QIODevice::Text);
    QTextStream out(&myfile);
    for(auto i=book.begin() ; i != book.end() ; i++)
        out << i.key() << " " << i.value().join(" ") << "\n";

    QMessageBox success;
    success.setText("The book has successfully deleted. Press \"Ok\" to return to Dashboard");
    success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
    success.setStandardButtons(QMessageBox::Ok);
    success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    success.setDefaultButton(QMessageBox::Ok);
    success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

    success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: rgb(196,255,3); color: black; border-radius:10px;}"

                "QPushButton:hover{ background-color: rgb(0, 255, 0);}"

                "QMessageBox{background-color: rgba(85, 170, 0 , 0.7); font:12pt Tw Cen MT Condensed Extra Bold;}");
    success.exec();

    load();

}

