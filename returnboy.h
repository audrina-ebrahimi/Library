#ifndef RETURNBOY_H
#define RETURNBOY_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class returnBoy;
}

class returnBoy : public QMainWindow
{
    Q_OBJECT

public:
    explicit returnBoy(QString user , QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();

    ~returnBoy();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::returnBoy *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
    QString user;
    QMap <QString , QStringList> book;
    QMap <QPair<QString , QString> , QDate> get_return;
};

#endif // RETURNBOY_H
