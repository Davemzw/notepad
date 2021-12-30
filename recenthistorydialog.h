#ifndef RECENTHISTORYDIALOG_H
#define RECENTHISTORYDIALOG_H

#include <QDialog>

namespace Ui {
class recenthistoryDialog;
}

class recenthistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit recenthistoryDialog(QWidget *parent = nullptr);
    ~recenthistoryDialog();

private:
    Ui::recenthistoryDialog *ui;
};

#endif // RECENTHISTORYDIALOG_H
