#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class editBook;
}

class editBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit editBook(QString isbn , QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~editBook();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_pushButton_clicked();



private:
    Ui::editBook *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * dash;
    QMap <QString , QStringList> book;
    QString isbn;

};

#endif // EDITBOOK_H
