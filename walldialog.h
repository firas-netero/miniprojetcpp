#ifndef WALLDIALOG_H
#define WALLDIALOG_H

#include <QDialog>
#include<QDate>
#include <QMainWindow>
#include<QMessageBox>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

namespace Ui {
class WallDialog;
}

class WallDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WallDialog(QWidget *parent = 0);
    ~WallDialog();

private:
    Ui::WallDialog *ui;
};

#endif // WALLDIALOG_H
