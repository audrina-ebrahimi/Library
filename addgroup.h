#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class AddGroup;
}

class AddGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddGroup(QWidget *Groupdash , QWidget *main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();


    ~AddGroup();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_addButton_clicked();

private:
    Ui::AddGroup *ui;
    QPointF oldPos;
    QWidget *main;
    QWidget *Groupdash;
    QMap <QString , QStringList> groups;
    QMap <QString , QStringList> books;

};

#endif // ADDGROUP_H
