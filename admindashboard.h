#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class admindashboard;
}

class admindashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit admindashboard(QWidget * login , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);



    ~admindashboard();

private slots:



    void on_menuButton_clicked();

    void on_closeButton_clicked();

    void on_logoutButton_clicked();

    void on_groupButton_clicked();

    void on_viewBookButton_clicked();

    void on_viewMemButton_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_situationButton_clicked();

private:
    Ui::admindashboard *ui;
    QWidget  *main;
    QPointF oldPos;
    QWidget * login;
};

#endif // ADMINDASHBOARD_H
