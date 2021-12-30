#ifndef MYHISTORYDIALOG_H
#define MYHISTORYDIALOG_H

#include <QDialog>
#include<QStringListModel>

namespace Ui {
class myhistoryDialog;
}

class myhistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myhistoryDialog(QWidget *parent = nullptr);
    ~myhistoryDialog();
    void add_history(QString filename);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::myhistoryDialog *ui;
    QStringListModel *theModel;
};

#endif // MYHISTORYDIALOG_H
