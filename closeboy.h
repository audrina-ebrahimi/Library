#ifndef CLOSEBOY_H
#define CLOSEBOY_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class closeBoy;
}

class closeBoy : public QMainWindow
{
    Q_OBJECT

public:
    explicit closeBoy(QWidget *main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~closeBoy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::closeBoy *ui;
    QWidget *main;
    QPointF oldPos;
};

#endif // CLOSEBOY_H
