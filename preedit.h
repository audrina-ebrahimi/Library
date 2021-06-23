#ifndef PREEDIT_H
#define PREEDIT_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class preEdit;
}

class preEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit preEdit(QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();

    ~preEdit();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_editButton_clicked();

private:
    Ui::preEdit *ui;
    QWidget * main;
    QWidget * dash;
    QPointF oldPos;
    QMap <QString , QStringList> book;
};

#endif // PREEDIT_H
