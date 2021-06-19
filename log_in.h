#ifndef LOG_IN_H
#define LOG_IN_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class log_in;
}

class log_in : public QMainWindow
{
    Q_OBJECT

public:
    explicit log_in( QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~log_in();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_log_in_Button_clicked();

private:
    Ui::log_in *ui;
    QPointF oldPos;
    QWidget * main;

};

#endif // LOG_IN_H
