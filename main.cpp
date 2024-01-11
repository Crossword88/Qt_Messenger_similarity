#include "mainwindow.h"
#include "fstream"
#include "iostream"
#include "string"
#include "fstream"
#include "QVector"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();

}
