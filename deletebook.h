#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>
#include <QFile>
namespace Ui {
class deleteBook;
}

class deleteBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteBook(QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();

    ~deleteBook();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::deleteBook *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * dash;
    QMap <QString , QStringList> book;
};

#endif // DELETEBOOK_H
