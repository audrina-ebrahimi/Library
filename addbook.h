#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class addBook;
}

class addBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit addBook(QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~addBook();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addBook *ui;
    QWidget * main;
    QWidget * dash;
    QPointF oldPos;
};

#endif // ADDBOOK_H
