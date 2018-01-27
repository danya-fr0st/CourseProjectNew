#ifndef INFOFORM_H
#define INFOFORM_H

#include <QWidget>

namespace Ui {
class InfoForm;
}

class InfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit InfoForm(QWidget *parent = 0);
    ~InfoForm();

private slots:
    void on_CloseHelpButton_clicked();

private:
    Ui::InfoForm *ui;
};

#endif // INFOFORM_H
