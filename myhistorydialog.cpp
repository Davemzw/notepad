#include "myhistorydialog.h"
#include "ui_myhistorydialog.h"
#include<QStringListModel>
#include<QTextCodec>
#include"newmainwindow.h"
#include "QFileDialog"
#include "QMessageBox"

myhistoryDialog::myhistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myhistoryDialog)
{
    ui->setupUi(this);
    QStringList theStrList;
    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->HistoryView->setModel(theModel);
    ui->HistoryView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

myhistoryDialog::~myhistoryDialog()
{
    delete ui;
}

void myhistoryDialog::add_history(QString filename)
{
    theModel->insertRow(theModel->rowCount());
    QModelIndex index=theModel->index(theModel->rowCount()-1,0);
    theModel->setData(index,filename,Qt::DisplayRole);
    ui->HistoryView->setCurrentIndex(index);
}


void myhistoryDialog::on_pushButton_clicked()
{
    QModelIndex index=ui->HistoryView->currentIndex();
    int i=index.row();
    QStringList tmpList;
    tmpList=theModel->stringList();
    QString filename=tmpList.value(i);
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","打开文件失败");
        return;
    }
    QByteArray con=file.readAll();
    QString text=codec->toUnicode(con);
    newMainWindow *newwindow=new newMainWindow(this);
     newwindow->openfile(text);
     newwindow->setWindowTitle(QFileInfo(filename).absoluteFilePath());
     newwindow->show();
    file.close();
 }


void myhistoryDialog::on_pushButton_2_clicked()
{
    accept();
}

