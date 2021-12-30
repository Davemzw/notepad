#include "newmainwindow.h"
#include "ui_newmainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTextStream"
#include<QTextCodec>
#include"replacedialog.h"
#include"searchdialog.h"
#include"aboutdialog.h"
newMainWindow::newMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newMainWindow)
{
    ui->setupUi(this);
    highlighter=new Highlighter(ui->textEdit1->document());
     dlg=new myhistoryDialog(this);
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

newMainWindow::~newMainWindow()
{
    delete ui;
}

void newMainWindow::openfile(QString text)
{
    ui->textEdit1->insertPlainText(text);
}

void newMainWindow::on_actionnew_triggered()
{
    if(!userEditConfirmed())
        return;

    filepath = "";
    ui->textEdit1->clear();
    this->setWindowTitle(tr("新建文本文件-编辑器"));
     textChanged = false;
}

bool newMainWindow::userEditConfirmed()
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


void newMainWindow::on_actionsave_triggered()
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
    QString text = ui->textEdit1->toPlainText();
    out<<text;
    file.flush();
    file.close();

     this->setWindowTitle(QFileInfo(filepath).absoluteFilePath());

    textChanged = false;
}


void newMainWindow::on_actionopen_triggered()
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
     dlg->add_history(this->windowTitle());
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


void newMainWindow::on_actionhistory_triggered()
{
    dlg->exec();
}


void newMainWindow::on_actioncexiao_triggered()
{
     ui->textEdit1->undo();
}


void newMainWindow::on_actionhuifu_triggered()
{
     ui->textEdit1->redo();
}


void newMainWindow::on_actioncut_triggered()
{
    ui->textEdit1->cut();
    ui->actionzhantie->setEnabled(true);
}


void newMainWindow::on_actioncopy_triggered()
{
    ui->textEdit1->copy();
    ui->actionzhantie->setEnabled(true);
}


void newMainWindow::on_actionzhantie_triggered()
{
     ui->textEdit1->paste();
}


void newMainWindow::on_actiontihuan_triggered()
{
    ReplaceDialog dlg(this,ui->textEdit1);
    dlg.exec();
}


void newMainWindow::on_actionsearch_triggered()
{
    SearchDialog dlg(this,ui->textEdit1);
    dlg.exec();
}


void newMainWindow::on_actiongbzt_triggered()
{
    int a=rand()%250;
    int b=rand()%250;
    int c=rand()%250;
    this->setPalette(QPalette(QColor(a,b,c)));
}


void newMainWindow::on_actionztl_triggered()
{
    bool visible= ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
}


void newMainWindow::on_action_A_triggered()
{
    aboutDialog dlg;
    dlg.exec();
}

