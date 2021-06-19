#ifndef SITUATION_H
#define SITUATION_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class situation;
}

class situation : public QMainWindow
{
    Q_OBJECT

public:
    explicit situation(QWidget * admin , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();
    ~situation();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::situation *ui;
    QWidget * admin;
    QWidget * main;
    QPointF oldPos;
    QMap <QPair<QString , QString> , QDate> get_return;
};

#endif // SITUATION_H
