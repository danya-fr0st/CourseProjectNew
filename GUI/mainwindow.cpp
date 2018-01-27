#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpform.h"
#include "infoform.h"
#include "helpform.cpp"
#include "infoform.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_HelpButton_clicked()
{
    f2 = new mainwindow2(this);
    this->hide();
    f2->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_HelpButton_clicked() //////////////при нажатии открывается список доступных команд
{
    AddDialog HelpButton(this);
    HelpButton.exec();
}

void MainWindow::on_InfoButton_clicked() /////////////какая-нибудь инфа
{
    AddDialog InfoButton(this);
    InfoButton.exec();
}

