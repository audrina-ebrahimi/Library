#ifndef BOYGET_H
#define BOYGET_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class boyGet;
}

class boyGet : public QMainWindow
{
    Q_OBJECT

public:
    explicit boyGet(QString user , QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void load();

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~boyGet();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_getButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::boyGet *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
    QString user;
    QMap <QString , QStringList> book;
    QMap <QPair<QString , QString> , QDate> get_return;
};

#endif // BOYGET_H
