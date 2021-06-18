#include "editgroup.h"
#include "ui_editgroup.h"
#include <QFile>
#include <QMessageBox>

editGroup::editGroup(QString groupName , QWidget *Groupdash , QWidget *main , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editGroup)
{
    ui->setupUi(this);
    this->qMain = main;
    this->Groupdash = Groupdash;
    this->groupName = groupName;
    load();

    for(int i=0 ; i<ui->tableWidget->rowCount() ; ++i)
    {
        if(groups.value(groupName).contains(ui->tableWidget->item(i,1)->text()))
           ui->tableWidget->selectRow(i);
    }

    groups.remove(groupName);
}

void editGroup::load()
{
    ui->tableWidget->setRowCount(0);
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

    int j=0;
    for(auto i=books.begin() ; i != books.end() ; i++)
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
}

editGroup::~editGroup()
{
    delete ui;
}

void editGroup::on_closeButton_clicked()
{
    this->close();
}


void editGroup::on_menuButton_clicked()
{
    qMain->show();
    this->close();
}


void editGroup::on_dashButton_clicked()
{
    Groupdash->show();
    this->close();
}


void editGroup::on_editButton_clicked()
{
    groups.remove(groupName);

    QList <QTableWidgetItem *> selected = ui->tableWidget->selectedItems();

    QStringList isbn;


    if(ui->nameEdit->text().size() != 0)
        groupName = ui->nameEdit->text();


    if(groups.contains(groupName))
    {
        QMessageBox repeated;
        repeated.setText("The name you chose for your group name already exists.\nPlease select another name.");
        repeated.setIcon(QMessageBox :: Critical);
        repeated.setStandardButtons(QMessageBox::Ok);
        repeated.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        repeated.setDefaultButton(QMessageBox::Ok);
        repeated.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        repeated.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #ab3e10; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #a35e26;}"

                    "QMessageBox{background-color: #f4a261; font:12pt Tw Cen MT Condensed Extra Bold; border: 4px solid brown;}");
        repeated.exec();
    }

    else
    {
        for (int i = 1; i < selected.size(); i+=8)
            isbn << selected.at(i)->text();


        groups.insert(groupName , isbn);


        QFile file("F:/Qt/Library/group.txt");
        file.open(QIODevice::Text | QIODevice :: WriteOnly);
        QTextStream out(&file);

        for(auto i=groups.begin() ; i!=groups.end() ; i++)
            out << i.key() << " " << i.value().join(" ") << "\n";

        QMessageBox success;
        success.setText("This group edited successfully.\nPress \"Ok\" to return to Group Dashboard.");
        success.setIconPixmap(QPixmap ("F:/Qt/Library/icons/check.png"));
        success.setStandardButtons(QMessageBox::Ok);
        success.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        success.setDefaultButton(QMessageBox::Ok);
        success.button(QMessageBox::Ok)->setCursor(Qt::PointingHandCursor);

        success.setStyleSheet("QPushButton{ width:100px; height:30px; background-color: #ab3e10; border-radius:10px;}"

                    "QPushButton:hover{ background-color: #a35e26;}"

                    "QMessageBox{background-color: #f4a261; font:14pt Tw Cen MT Condensed Extra Bold; border: 4px solid brown;}");
        if(success.exec())
        {
            Groupdash->show();
            this->close();
        }
    }
}

