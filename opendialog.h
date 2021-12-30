#ifndef OPENDIALOG_H
#define OPENDIALOG_H

#include <QDialog>

namespace Ui {
class openDialog;
}

class openDialog : public QDialog
{
    Q_OBJECT

public:
    explicit openDialog(QWidget *parent = nullptr);
    ~openDialog();

private:
    Ui::openDialog *ui;
};

#endif // OPENDIALOG_H
