#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class userdashboard;
}

class userdashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit userdashboard(QWidget *parent = nullptr);
    ~userdashboard();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::userdashboard *ui;
};

#endif // USERDASHBOARD_H
