#include "perdio.h"
#include "ui_perdio.h"

perdio::perdio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::perdio)
{
    ui->setupUi(this);
}

perdio::~perdio()
{
    delete ui;
}
