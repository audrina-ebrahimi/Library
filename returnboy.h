#ifndef RETURNBOY_H
#define RETURNBOY_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class returnBoy;
}

class returnBoy : public QMainWindow
{
    Q_OBJECT

public:
    explicit returnBoy(QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~returnBoy();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

private:
    Ui::returnBoy *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
};

#endif // RETURNBOY_H
