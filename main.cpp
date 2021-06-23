//https://github.com/adrina-ei/Library

#include "mainwindow.h"
#include <QApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
