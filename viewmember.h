#ifndef VIEWMEMBER_H
#define VIEWMEMBER_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class viewMember;
}

class viewMember : public QMainWindow
{
    Q_OBJECT

public:

    explicit viewMember(QWidget * admin , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void update();

    ~viewMember();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_deleteButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::viewMember *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * admin;
    QMap <QString , QString> user_pass;
};

#endif // VIEWMEMBER_H
