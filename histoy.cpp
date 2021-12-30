#include "histoy.h"
#include "ui_histoy.h"

histoy::histoy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histoy)
{
    ui->setupUi(this);
}

histoy::~histoy()
{
    delete ui;
}
