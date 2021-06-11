#ifndef GIRLGET_H
#define GIRLGET_H

#include <QMainWindow>
#include <QMap>
#include <QMouseEvent>
namespace Ui {
class girlGet;
}

class girlGet : public QMainWindow
{
    Q_OBJECT

public:
    explicit girlGet(QWidget *dash , QWidget *main , QWidget *parent = nullptr);

    void load();

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~girlGet();

private slots:
    void on_closeButton_clicked();

    void on_dashButton_clicked();

    void on_menuButton_clicked();

private:
    Ui::girlGet *ui;
    QWidget *main;
    QWidget *dash;
    QPointF oldPos;
    QMap <QString , QStringList> book;
};

#endif // GIRLGET_H
