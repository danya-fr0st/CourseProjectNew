#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpdialog.h"
#include "infodialog.h"
#include <QInputDialog>
#include "ROM_memory.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void StreamOut(QString text);
    QString ReceiveCommand();



private slots:
    void on_InfoButton_clicked();

    void on_HelpButton_clicked();

    void on_CompileButton_clicked();

    void on_SaveButton_clicked();

    void on_textBrowser_textChanged();

    void OpenAction_clicked();

    void SaveAction_clicked();

    void ExitAction_clicked();


private:
    Ui::MainWindow *ui;
    InfoDialog *iWindow;
    HelpDialog *hWindow;
    ROM_memory rom_mem;


};

#endif // MAINWINDOW_H
