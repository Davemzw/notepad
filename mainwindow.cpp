#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText("启动服务器");
    static bool started=false;
     started=!started;
    if(started)
    {
        ui->pushButton->setText("停止服务器");
        logMessage("服务器已经启动");
    }
    else
    {
        ui->pushButton->setText("启动服务器");
        logMessage("服务器已经停止");
    }

}

void MainWindow::logMessage(const QString &msg)
{
    ui->plainTextEdit->appendPlainText(msg);
}

