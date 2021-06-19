#ifndef VIEWGIRL_H
#define VIEWGIRL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>

namespace Ui {
class viewgirl;
}

class viewgirl : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewgirl(QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    QString get_user();

    void load();

    ~viewgirl();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_DashButton_clicked();

    void on_searchEdit_textChanged(const QString &arg1);

private:
    Ui::viewgirl *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * dash;
    QMap <QString , QStringList> book;
};

#endif // VIEWGIRL_H
