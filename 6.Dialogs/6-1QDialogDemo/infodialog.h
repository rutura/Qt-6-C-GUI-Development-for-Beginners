#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    const QString &position() const;
    const QString &favorite_os() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    QString m_position;
    QString m_favorite_os;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
