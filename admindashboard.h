#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class admindashboard;
}

class admindashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit admindashboard(QWidget *parent = nullptr);
    ~admindashboard();

private slots:
    void on_menuButton_clicked();

    void on_closeButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::admindashboard *ui;
};

#endif // ADMINDASHBOARD_H
