#ifndef GIRL_GET_H
#define GIRL_GET_H

#include <QMainWindow>

namespace Ui {
class girl_get;
}

class girl_get : public QMainWindow
{
    Q_OBJECT

public:
    explicit girl_get(QWidget *parent = nullptr);
    ~girl_get();

private:
    Ui::girl_get *ui;
};

#endif // GIRL_GET_H
