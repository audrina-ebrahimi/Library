#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class sign_up;
}

class sign_up : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_up(QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~sign_up();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_sign_up_Button_clicked();

private:
    Ui::sign_up *ui;
    QPointF oldPos;
    QWidget * main;
};

#endif // SIGN_UP_H
