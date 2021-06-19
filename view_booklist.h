#ifndef VIEW_BOOKLIST_H
#define VIEW_BOOKLIST_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class view_booklist;
}

class view_booklist : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_booklist(QWidget * admin , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~view_booklist();

private slots:

    void load();

    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::view_booklist *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * admin;
    QMap <QString , QStringList> book;
};

#endif // VIEW_BOOKLIST_H
