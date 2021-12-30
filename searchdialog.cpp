#include "searchdialog.h"
#include "ui_searchdialog.h"
#include "QMessageBox"

SearchDialog::SearchDialog(QWidget *parent,QTextEdit * textEdit) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    pTextEdit = textEdit;
    ui->rbDown1->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_pushButton_2_clicked()
{
    QString target = ui->searchText->text();
    if(target == ""||pTextEdit == nullptr)
        return;
    QString text = pTextEdit->toPlainText();
    QTextCursor c = pTextEdit->textCursor();
    int index = -1;
    if(ui->rbDown1->isChecked()){
        index = text.indexOf(target,c.position(),
                             ui->cb->isChecked() ?Qt::CaseSensitive : Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }

    }else if(ui->rbUp->isChecked()){
        index= text.lastIndexOf(target,c.position()-text.length()-1,
                                ui->cb->isChecked() ?Qt::CaseSensitive : Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index+target.length());
            c.setPosition(index,QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);

        }
    }

    if(index<0){
        QMessageBox msg(this);
        msg.setWindowTitle("jishiben");
        msg.setText(QString("找不到")+target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}


void SearchDialog::on_pushButton_clicked()
{
    accept();
}

