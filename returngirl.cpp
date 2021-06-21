#include "returngirl.h"
#include "ui_returngirl.h"

#include <QFile>
#include <QDate>
#include <QMessageBox>

returnGirl::returnGirl(QString user , QWidget *dash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::returnGirl)
{
    ui->setupUi(this);

    //Transfer main, dash and username
    this->qMain = main;
    this->dash = dash;
    this->user = user;

    //Fill the table map
    load();
}

//Function for filling the table widget and maps
void returnGirl::load()
{
    ui->tableWidget->setRowCount(0);

    //Read data from file and fill the books map
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

    myfile.close();

    //Read data from file and fill the get and return map
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
    for(auto i=get_return.begin() ; i != get_return.end() ; ++i)
    {
        if(i.key().first == user)
        {
            //Calculate expire date
            QDate current = QDate:: currentDate();
            int d = current.daysTo(i.value());

            //isbn
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            QTableWidgetItem *isbn1 = new QTableWidgetItem();

            //Yellow for 1 or 0 day left and red for expired
            if(d == 1 || d == 0)
                isbn1->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn1->setBackground(QBrush(QColor(239,129,130)));

            isbn1->setText(i.key().second);
            ui->tableWidget->setItem(j,1,isbn1);



            //book name
            QTableWidgetItem *isbn2 = new QTableWidgetItem();

            //Yellow for 1 or 0 day left and red for expired
            if(d == 1 || d == 0)
                isbn2->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn2->setBackground(QBrush(QColor(239,129,130)));

            isbn2->setText(book.value(i.key().second).at(0));
            ui->tableWidget->setItem(j,0,isbn2);



            //return date
            QTableWidgetItem *isbn3 = new QTableWidgetItem();

            //Yellow for 1 or 0 day left and red for expired
            if(d == 1 || d == 0)
                isbn3->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn3->setBackground(QBrush(QColor(239,129,130)));

            isbn3->setText(i.value().toString("yyyy MMM dd"));
            ui->tableWidget->setItem(j,8,isbn3);



            //get date
            QTableWidgetItem *isbn4 = new QTableWidgetItem();

            //Yellow for 1 or 0 day left and red for expired
            if(d == 1 || d == 0)
                isbn4->setBackground(QBrush(QColor(255,234,0)));
            else if( d<0 )
                isbn4->setBackground(QBrush(QColor(239,129,130)));

            QDate get_day = i.value().addDays(-7);
            isbn4->setText(get_day.toString("yyyy MMM dd"));
            ui->tableWidget->setItem(j,7,isbn4);


            //Other book information
            for(int k=1 ; k<book.value(i.key().second).size()-1 ; ++k)
            {
                QTableWidgetItem *isbn5 = new QTableWidgetItem();

                //Yellow for 1 or 0 day left and red for expired
                if(d == 1 || d == 0)
                    isbn5->setBackground(QBrush(QColor(255,234,0)));
                else if( d<0 )
                    isbn5->setBackground(QBrush(QColor(239,129,130)));

                isbn5->setText(book.value(i.key().second).at(k));
                ui->tableWidget->setItem(j , k+1 , isbn5);
            }

            j++;
        }
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

//Dragable
void returnGirl::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void returnGirl::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

returnGirl::~returnGirl()
{
    delete ui;
}

//Close, menu and dash
void returnGirl::on_closeButton_clicked()
{
    this->close();
}

void returnGirl::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void returnGirl::on_dashButton_clicked()
{
    dash->show();
    this->close();
}

//Return book
void returnGirl::on_getButton_clicked()
{

    //Get the book's ISBN
    QString isbn = ui->tableWidget->selectedItems()[1]->text();

    //Remove book from get and return map
    get_return.remove(qMakePair(user , isbn));

    //Fill the file with new map
    QFile myfile("F:/Qt/Library/get_return.txt");
    myfile.open(QIODevice::Text | QIODevice :: WriteOnly);
    QTextStream out(&myfile);

    for(auto i=get_return.begin() ; i!=get_return.end() ; ++i)
        out << i.key().first << " " << i.key().second << " " << i.value().toString("yyyyMMdd") << "\n";

    myfile.close();

    //Add one to availablity
    book[isbn][6] = QString::number(book[isbn].at(6).toInt()+1);

    //Fill the file with new map
    QFile file("F:/Qt/Library/books.txt");
    file.open(QIODevice :: WriteOnly | QIODevice::Text);
    QTextStream out2(&file);
    for(auto i=book.begin() ; i != book.end() ; i++)
        out2 << i.key() << " " << i.value().join(" ") << "\n";
    file.close();

    QMessageBox success;
    success.setText("Your book successfuly returned!");

    success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
    success.setStandardButtons(QMessageBox::Ok);
    success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    success.setDefaultButton(QMessageBox::Ok);
    success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

    success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #AC0C0F; color: #B8B8B8; border-radius:10px;}"

                "QPushButton:hover{ background-color: #E84A4D;}"

                "QMessageBox{background-color: #B8B8B8; font:12pt Tw Cen MT Condensed Extra Bold; border: 2px solid red;}");
    success.exec();

    load();
}

