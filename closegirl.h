#ifndef CLOSEGIRL_H
#define CLOSEGIRL_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class closeGirl;
}

class closeGirl : public QMainWindow
{
    Q_OBJECT

public:
    explicit closeGirl(QWidget *main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~closeGirl();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::closeGirl *ui;
    QWidget *main;
    QPointF oldPos;
};

#endif // CLOSEGIRL_H
