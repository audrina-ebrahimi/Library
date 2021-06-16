#ifndef RETURNGIRL_H
#define RETURNGIRL_H

#include <QMainWindow>
#include <QMap>
#include <QMouseEvent>
namespace Ui {
class returnGirl;
}

class returnGirl : public QMainWindow
{
    Q_OBJECT

public:
    explicit returnGirl(QString user , QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void load();

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~returnGirl();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_getButton_clicked();

private:
    Ui::returnGirl *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
    QString user;
    QMap <QString , QStringList> book;
    QMap <QPair<QString , QString> , QDate> get_return;
};

#endif // RETURNGIRL_H
