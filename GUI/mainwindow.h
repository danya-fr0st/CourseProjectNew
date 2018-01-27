#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //mainwindow2 *f2;
private slots:

    void on_HelpButton_clicked();

    void on_InfoButton_clicked();

private:
    Ui::MainWindow *ui;
    void MainWindow::on_HelpButton_clicked() {}
};

#endif // MAINWINDOW_H
