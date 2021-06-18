#include "groupbooks.h"
#include "ui_groupbooks.h"
#include <QList>
#include "mainwindow.h"
#include "admindashboard.h"
#include "addgroup.h"
#include "editgroup.h"
#include <QMessageBox>

GroupBooks::GroupBooks(QWidget * admin , QWidget * main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GroupBooks)
{
    ui->setupUi(this);

    this->qMain = main;
    this->admin = admin;
    load();
}

void GroupBooks::mousePressEvent(QMouseEvent *event)
{
    oldPos = event->globalPosition();
}

void GroupBooks::mouseMoveEvent(QMouseEvent *event)
{
    const QPointF delta = event->globalPosition() - oldPos;
    move(x() + delta.x() , y() + delta.y());
    oldPos = event->globalPosition();
}

void GroupBooks::load()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("Groups");

    QFile myfile("F:/Qt/Library/books.txt");
    myfile.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in(&myfile);

    books.clear();
    while(!in.atEnd())
    {
       QStringList line = in.readLine().split(" ");
       books[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           books[line[0]] << line.at(i);
    }

    myfile.close();


    QFile file("F:/Qt/Library/group.txt");
    file.open(QIODevice::Text | QIODevice :: ReadOnly);
    QTextStream in1(&file);

    groups.clear();
    while(!in1.atEnd())
    {
       QStringList line = in1.readLine().split(" ");
       groups[line[0]] << line[1];
       for(int i=2 ; i<line.size() ; i++)
           groups[line[0]] << line.at(i);
    }


    file.close();

    for(auto i=groups.begin() ; i!=groups.end() ; ++i)
    {
        QTreeWidgetItem * group_name = new QTreeWidgetItem(ui->treeWidget);
        group_name->setText(0 , i.key());


        for(int j = 0; j<i.value().size(); ++j)
        {
            QTreeWidgetItem * book_name = new QTreeWidgetItem();
            book_name->setFlags(Qt::ItemIsSelectable);
            book_name->setText(0 , books.value(i.value().at(j)).at(0));


            QTreeWidgetItem * isbn = new QTreeWidgetItem();
            isbn->setText(0 , "ISBN: " + i.value().at(j));
            book_name->addChild(isbn);

            QTreeWidgetItem * author = new QTreeWidgetItem();
            author->setText(0, "Author: " + books.value(i.value().at(j)).at(1));
            book_name->addChild(author);

            QTreeWidgetItem * subject = new QTreeWidgetItem();
            subject->setText(0, "Subject: " + books.value(i.value().at(j)).at(2));
            book_name->addChild(subject);

            QTreeWidgetItem * publisher = new QTreeWidgetItem();
            publisher->setText(0, "Publisher: " + books.value(i.value().at(j)).at(3));
            book_name->addChild(publisher);

            QTreeWidgetItem * language = new QTreeWidgetItem();
            language->setText(0, "Publisher: " + books.value(i.value().at(j)).at(4));
            book_name->addChild(language);

            QTreeWidgetItem * page = new QTreeWidgetItem();
            page->setText(0, "Number of pages: " + books.value(i.value().at(j)).at(5));
            book_name->addChild(page);

            QTreeWidgetItem * avail = new QTreeWidgetItem();
            avail->setText(0, "Availablities: " + books.value(i.value().at(j)).at(6));
            book_name->addChild(avail);

            for (int k = 0; k < book_name->childCount(); ++k)
                book_name->child(k)->setFlags(Qt::ItemIsSelectable);

            group_name->addChild(book_name);
        }
        ui->treeWidget->addTopLevelItem(group_name);
    }
}

GroupBooks::~GroupBooks()
{
    delete ui;
}



void GroupBooks::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}

void GroupBooks::on_dashButton_clicked()
{
    admin->show();
    this->close();
}

void GroupBooks::on_closeButton_clicked()
{
    this->close();
}

void GroupBooks::on_addButton_clicked()
{
    AddGroup * add = new AddGroup(this , qMain);
    add->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    add->show();
    this->close();
}


void GroupBooks::on_refreshButton_clicked()
{
    load();
}


void GroupBooks::on_editButton_clicked()
{
    if(ui->treeWidget->selectedItems().size() == 0)
    {
        QMessageBox failed;
        failed.setText("You haven't chosen any group to edit yet.\nPlease select one.");
        failed.setIcon(QMessageBox :: Critical);
        failed.setStandardButtons(QMessageBox::Ok);
        failed.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        failed.setDefaultButton(QMessageBox::Ok);
        failed.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        failed.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #4361ee; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #3b28cc;}"

                    "QMessageBox{background-color: #14fff7; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid blue;}");
        failed.exec();
    }
    else
    {
        QString groupName = ui->treeWidget->selectedItems().at(0)->text(0);

        editGroup * edit = new editGroup(groupName , this , qMain);
        edit->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        edit->show();
        this->close();
    }
}


void GroupBooks::on_deteleButton_clicked()
{
    if(ui->treeWidget->selectedItems().size() == 0)
    {
        QMessageBox failed;
        failed.setText("You haven't chosen any group to delete yet.\nPlease select one.");
        failed.setIcon(QMessageBox :: Critical);
        failed.setStandardButtons(QMessageBox::Ok);
        failed.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        failed.setDefaultButton(QMessageBox::Ok);
        failed.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        failed.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #4361ee; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #3b28cc;}"

                    "QMessageBox{background-color: #14fff7; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid blue;}");
        failed.exec();
    }
    else
    {
        groups.remove(ui->treeWidget->selectedItems().at(0)->text(0));

        QFile file("F:/Qt/Library/group.txt");
        file.open(QIODevice::Text | QIODevice :: WriteOnly);
        QTextStream out(&file);

        for(auto i=groups.begin() ; i!=groups.end() ; i++)
            out << i.key() << " " << i.value().join(" ") << "\n";

        QMessageBox success;
        success.setText("This group deleted successfully.\nPress \"Refresh List\" to refresh the group table.");
        success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
        success.setStandardButtons(QMessageBox::Ok);
        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #4361ee; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #3b28cc;}"

                    "QMessageBox{background-color: #14fff7; font:14pt Tw Cen MT Condensed Extra Bold; border: 4px solid blue;}");
        success.exec();

    }
}

