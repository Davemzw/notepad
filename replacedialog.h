#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr,QTextEdit *textEdit =nullptr);
    ~ReplaceDialog();

private slots:
    void on_btFindNext_clicked();

    void on_btExchange_clicked();

    void on_btExchangeAll_clicked();

    void on_btCancel_clicked();

private:
    Ui::ReplaceDialog *ui;
    QTextEdit * pTextEdit;
};

#endif // REPLACEDIALOG_H
