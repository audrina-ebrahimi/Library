#ifndef EDITGROUP_H
#define EDITGROUP_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class editGroup;
}

class editGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit editGroup(QString groupName , QWidget *Groupdash , QWidget *main , QWidget *parent = nullptr);

    void load();

    ~editGroup();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_editButton_clicked();

private:
    Ui::editGroup *ui;
    QWidget *Groupdash;
    QWidget *main;
    QMap <QString , QStringList> groups;
    QMap <QString , QStringList> books;
    QString groupName;
};

#endif // EDITGROUP_H
