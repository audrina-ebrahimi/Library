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
    explicit userdashboard(QString user , QWidget *parent = nullptr);
    QString get_user();
    ~userdashboard();

private slots:
    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::userdashboard *ui;
    QString user;
};

#endif // USERDASHBOARD_H
