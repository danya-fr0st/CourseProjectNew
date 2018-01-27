#include "helpform.h"
#include "ui_helpform.h"

HelpForm::HelpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
}

HelpForm::~HelpForm()
{
    delete ui;
}
