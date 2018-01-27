#include "mainwindow.h"
#include "mainwindow.cpp"
#include "helpform.h"
#include "infoform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    InfoForm example;
    HelpForm example1;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    example.show();
    example1.show();
    return a.exec();
}
