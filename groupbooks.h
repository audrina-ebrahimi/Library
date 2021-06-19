#ifndef GROUPBOOKS_H
#define GROUPBOOKS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class GroupBooks;
}

class GroupBooks : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupBooks(QWidget * admin , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();

    ~GroupBooks();

private slots:



    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_closeButton_clicked();

    void on_addButton_clicked();

    void on_refreshButton_clicked();

    void on_editButton_clicked();

    void on_deteleButton_clicked();

private:
    Ui::GroupBooks *ui;

    QPointF oldPos;

    QWidget * main;
    QWidget * admin;
    QMap <QString , QStringList> groups;
    QMap <QString , QStringList> books;
};

#endif // GROUPBOOKS_H
