#ifndef BOYGET_H
#define BOYGET_H

#include <QMainWindow>
#include <QMap>
#include <QMouseEvent>
namespace Ui {
class boyGet;
}

class boyGet : public QMainWindow
{
    Q_OBJECT

public:
    explicit boyGet(QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void load();

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~boyGet();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

private:
    Ui::boyGet *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
    QMap <QString , QStringList> book;
};

#endif // BOYGET_H
