#ifndef CHOOSE_GENDER_H
#define CHOOSE_GENDER_H

#include <QMainWindow>

namespace Ui {
class choose_gender;
}

class choose_gender : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose_gender(QWidget *parent = nullptr);
    ~choose_gender();

private slots:
    void on_menuButton_clicked();

    void on_closeButton_clicked();

    void on_girl_Button_clicked();

private:
    Ui::choose_gender *ui;
};

#endif // CHOOSE_GENDER_H
