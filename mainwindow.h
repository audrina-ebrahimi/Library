#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    ~MainWindow();

private slots:



    void on_closeButton_clicked();

    void on_login_Button_clicked();

    void on_signup_Button_clicked();

private:
    Ui::MainWindow *ui;
    QPointF oldPos;
};
#endif // MAINWINDOW_H
