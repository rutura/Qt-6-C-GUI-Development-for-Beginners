#include "suredialog.h"
#include "ui_suredialog.h"

SureDialog::SureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SureDialog)
{
    ui->setupUi(this);
}

SureDialog::~SureDialog()
{
    delete ui;
}
