#include "walldialog.h"
#include "ui_walldialog.h"
#include"mainwindow.h"

WallDialog::WallDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("TAKRIZ BLOG SPOT");
}

WallDialog::~WallDialog()
{
    delete ui;
}

