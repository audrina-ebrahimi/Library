#ifndef BOYDASHBOARD_H
#define BOYDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class boydashboard;
}

class boydashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit boydashboard(QString user , QWidget *parent = nullptr);
    QString get_user();
    ~boydashboard();

private slots:
    void on_logoutButton_clicked();

    void on_closeButton_clicked();

    void on_menuButton_clicked();

private:
    Ui::boydashboard *ui;
    QString user;
};

#endif // BOYDASHBOARD_H
