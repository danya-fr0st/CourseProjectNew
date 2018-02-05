#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include "string"
#include "vector"
#include <iomanip>
#include <fstream>
#include "ROM_memory.h"
#include "word.h"
#include "dword.h"
#include "memory.h"
#include <locale.h>

int main(int argc, char *argv[])
{

//    while (input != "end")
//    {
//        std::cin >> input;
//        test.parser(input);
//        system("pause");
//        system("cls");
//    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.StreamOut(QString("Emulator is available for using\n"));
    return a.exec();
}
