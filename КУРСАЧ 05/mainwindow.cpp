#include "mainwindow.h"
#include "ui_mainwindow.h"

void updateLabels(Ui::MainWindow *ui, ROM_memory& mem){
    ui->EAX_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_reg_by_string("EAX"))));
    ui->EBX_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_reg_by_string("EBX"))));
    ui->ECX_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_reg_by_string("ECX"))));
    ui->EDX_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_reg_by_string("EDX"))));
    ui->CR0_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_spec_reg_by_string("CR0"))));
    ui->CR1_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_spec_reg_by_string("CR1"))));
    ui->CR2_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_spec_reg_by_string("CR2"))));
    ui->CR3_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_spec_reg_by_string("CR3"))));
    ui->Flags_Value_Label->setText(QString::fromStdString(to_bin_str(mem.return_flags_by_string("Flags"))));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iWindow = new InfoDialog;
    connect(iWindow, &InfoDialog::iWindowOpen, this, &InfoDialog::show);
    hWindow = new HelpDialog;
    connect(hWindow, &HelpDialog::hWindowOpen, this, &HelpDialog::show);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_CompileButton_clicked);
    connect(ui->OpenAction, &QAction::triggered, this, &MainWindow::OpenAction_clicked);
    connect(ui->ExitAction, &QAction::triggered, this, &MainWindow::ExitAction_clicked);
    updateLabels(ui, rom_mem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StreamOut(QString text)
{
   ui->textBrowser->append(text);
}

QString MainWindow::ReceiveCommand()
{
    QString tmp = ui->lineEdit->text();
    ui->lineEdit->del();
    return tmp;
}

void MainWindow::on_InfoButton_clicked()
{
    iWindow->show();
    //this->close();
}


void MainWindow::on_HelpButton_clicked()
{
    hWindow->show();
    //this->close();
}

void MainWindow::on_CompileButton_clicked()
{
    QString Text = ui->lineEdit ->text();
    ui->lineEdit->clear();
    this->StreamOut(Text);
    rom_mem.parser(Text.toStdString());
    updateLabels(ui, rom_mem);
}
/*    else if (input == "open") file_parser();
else if (input == "exit") return false;
*/

void MainWindow::OpenAction_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Open file"), tr("Filename:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty())
        rom_mem.file_parser(text.toStdString());
    updateLabels(ui, rom_mem);
}

void MainWindow::SaveAction_clicked()
{

}

void MainWindow::ExitAction_clicked()
{
    this->close();
}




