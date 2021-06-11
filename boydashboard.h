#ifndef BOYDASHBOARD_H
#define BOYDASHBOARD_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class boydashboard;
}

class boydashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit boydashboard(QWidget * main , QString user , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    QString get_user();
    ~boydashboard();

private slots:



    void on_logoutButton_clicked();

    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_listButton_clicked();

    void on_pushButton_clicked();

    void on_getButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::boydashboard *ui;
    QPointF oldPos;
    QString user;
    QWidget * main;

};

#endif // BOYDASHBOARD_H
