#include "recenthistorydialog.h"
#include "ui_recenthistorydialog.h"

recenthistoryDialog::recenthistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recenthistoryDialog)
{
    ui->setupUi(this);
}

recenthistoryDialog::~recenthistoryDialog()
{
    delete ui;
}
