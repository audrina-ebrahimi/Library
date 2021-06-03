#ifndef CHOOSE_GENDER_H
#define CHOOSE_GENDER_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPointF>
namespace Ui {
class choose_gender;
}

class choose_gender : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose_gender(QWidget * login , QWidget * main , QString user , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    QString get_user();

    ~choose_gender();

private slots:



    void on_menuButton_clicked();

    void on_closeButton_clicked();

    void on_girl_Button_clicked();

    void on_boy_Button_clicked();

private:
    Ui::choose_gender *ui;
    QPointF oldPos;
    QString user;
    QWidget * main;
    QWidget * login;
};

#endif // CHOOSE_GENDER_H
