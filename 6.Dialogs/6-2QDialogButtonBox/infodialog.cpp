#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}


const QString &InfoDialog::position() const
{
    return m_position;
}

const QString &InfoDialog::favorite_os() const
{
    return m_favorite_os;
}


void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if( stdButton == QDialogButtonBox::Ok)
    {
        accept();
        qDebug() << "OK button Clicked";
    }
    if( stdButton == QDialogButtonBox::Save)
    {
        qDebug() << "Save button Clicked";
    }

    if( stdButton == QDialogButtonBox::SaveAll)
    {
        qDebug() << "SaveAll button Clicked";
    }
    if( stdButton == QDialogButtonBox::Open)
    {
        qDebug() << "Open button Clicked";
    }

    if( stdButton == QDialogButtonBox::Cancel)
    {
        reject();
        qDebug() << "Cancel button Clicked";
    }

}

