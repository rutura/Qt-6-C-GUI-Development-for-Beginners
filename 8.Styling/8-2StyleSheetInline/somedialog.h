#ifndef SOMEDIALOG_H
#define SOMEDIALOG_H

#include <QDialog>

namespace Ui {
class SomeDialog;
}

class SomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SomeDialog(QWidget *parent = nullptr);
    ~SomeDialog();

private:
    Ui::SomeDialog *ui;
};

#endif // SOMEDIALOG_H
