#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QTextStream"
#include "QColorDialog"
#include "QFontDialog"
#include"highlighter.h"
#include<QTextCodec>
#include"myhistorydialog.h"
#include"newmainwindow.h"
#include"searchdialog.h"
#include"replacedialog.h"
#include"aboutdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    highlighter=new Highlighter(ui->textEdit->document());
    dlg=new myhistoryDialog(this);
    ui->actionzdhh->setEnabled(false);
    textChanged=false;
    statusLabel.setMaximumWidth(180);
    statusLabel.setText("length:"+QString::number(0)+"lines:"+QString::number(1));
    ui->statusbar->addPermanentWidget(&statusLabel);

    statusCursorLabel.setMaximumWidth(180);
    statusCursorLabel.setText("Ln:"+QString::number(0)+"  Col:"+QString::number(1));
    ui->statusbar->addPermanentWidget(&statusCursorLabel);

    QLabel *author = new QLabel(ui->statusbar);
    author->setText(tr("马壮武"));
    ui->statusbar->addPermanentWidget(author);

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::userEditConfirmed()
{
    if(textChanged){
        QString path = (filepath !="")?filepath : "无标题.txt";

        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("...");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(QString("是否将更改保存到\n")+"\""+path+"\"?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        int r = msg.exec();
        switch (r) {
        case QMessageBox::Yes:
            on_actionsave_triggered();
            break;
        case QMessageBox::No:
            textChanged = false;
            break;
        case QMessageBox::Cancel:
            return false;

        }
    }
    return true;
}
void MainWindow::on_actionnew_triggered()
{
    if(!userEditConfirmed())
        return;

    filepath = "";
    ui->textEdit->clear();
    this->setWindowTitle(tr("新建文本文件-编辑器"));
     textChanged = false;
}


void MainWindow::on_actionsave_triggered()
{
    if(filepath == "")
    {
        QString filename= QFileDialog::getSaveFileName(this,"保存文件",".",
                                                       tr("Text files (*.txt) "));
        QFile file(filename);
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {

            QMessageBox::warning(this,"..","打开保存文件失败");
            return;
        }
        file.close();
        filepath = filename;
     }

    QFile file(filepath);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {

        QMessageBox::warning(this,"..","保存文件失败");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

     this->setWindowTitle(QFileInfo(filepath).absoluteFilePath());

    textChanged = false;
}


void MainWindow::on_actionopen_triggered()
{
    if(!userEditConfirmed())
        return;

    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QString filename = QFileDialog::getOpenFileName(this,"打开文件",".",tr("Text files (*.txt) ;; All (*.*)"));

    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","打开文件失败");
        return;

     }

    filepath = filename;
    dlg->add_history(filepath);
    QByteArray con=file.readAll();
    QString text=codec->toUnicode(con);
    newMainWindow *newwindow=new newMainWindow(this);
     newwindow->openfile(text);
     newwindow->setWindowTitle(QFileInfo(filename).absoluteFilePath());
     newwindow->show();
    file.close();

    textChanged = false;

 }


void MainWindow::on_actioncexiao_triggered()
{
     ui->textEdit->undo();
}


void MainWindow::on_actionhuifu_triggered()
{
     ui->textEdit->redo();
}


void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
    ui->actionzhantie->setEnabled(true);
}


void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
    ui->actionzhantie->setEnabled(true);
}



void MainWindow::on_actionzhantie_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionhistory_triggered()
{
    dlg->exec();
}


void MainWindow::on_actionsearch_triggered()
{
    SearchDialog dlg11(this,ui->textEdit);
    dlg11.exec();
}


void MainWindow::on_actiontihuan_triggered()
{
    ReplaceDialog dlg(this,ui->textEdit);
    dlg.exec();
}


void MainWindow::on_actionzdhh_triggered()
{
    QTextEdit::LineWrapMode mode = ui->textEdit->lineWrapMode();

    if(mode == QTextEdit::NoWrap){
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        ui->actionzdhh->setChecked(true);
    }else{
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);

        ui->actionzdhh->setChecked(false);
    }
}


void MainWindow::on_actionyfglfa_triggered()
{
    int a=rand()%250;
    int b=rand()%250;
    int c=rand()%250;
    this->setPalette(QPalette(QColor(a,b,c)));

}


void MainWindow::on_actionztl_triggered()
{
    bool visible= ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
}


void MainWindow::on_action_A_triggered()
{
    aboutDialog dlg;
    dlg.exec();
}

