#ifndef VIEWBOY_H
#define VIEWBOY_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMap>
namespace Ui {
class viewboy;
}

class viewboy : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewboy(QWidget * dash , QWidget * main , QWidget *parent = nullptr);

    void mousePressEvent (QMouseEvent * event);

    void mouseMoveEvent (QMouseEvent * event);

    void load();

    QString get_user();
    ~viewboy();

private slots:



    void on_closeButton_clicked();

    void on_menuButton_clicked();

    void on_dashButton_clicked();

    void on_searchEdit_textChanged(const QString &arg1);

private:
    Ui::viewboy *ui;
    QPointF oldPos;
    QWidget * main;
    QWidget * dash;
    QMap <QString , QStringList> book;
};

#endif // VIEWBOY_H
