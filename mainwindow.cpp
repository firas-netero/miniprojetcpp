#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


/**
 * @brief
 *
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(1);

}

/**
 * @brief
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}

/**
 * @brief
 *pass
 *
 */
void MainWindow::on_pushButton_clicked()
{

    QString password ="defaultpass";
    QString username ="defaultname";
    username=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    QString auth;
    QSqlDatabase db=QSqlDatabase ::addDatabase("QMYSQL");//QSQLITE
    db.setConnectOptions();
    db.setHostName("127.0.0.1");
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("Ben3ar9a");
    if (db.open())
    {
        qDebug() << "yeah it is open!!!!!!";
        QSqlQuery  query;
        if(query.exec("SELECT * FROM  userinfo"))
        {
            while (query.next() )
            {
                if((query.value(1).toString()==username))
                {
                        auth=query.value(2).toString();
                        //qDebug () << query.value(2).toString();
                 }
            }
        }
        else
        {
            qDebug () << "error"<<db.lastError().text();
        }
         db.close();
    }

    else
    {
        qDebug () << "error"<<db.lastError().text();
    }
    if((password== auth)&&(username!="") &&(password !=""))
    {
        //QMessageBox :: information(this,"Sign in","welcome");
        hide();
        wall=new WallDialog (this);
        wall->show();

    }
    else
        QMessageBox :: warning(this,"Sign up","password or username incorrect");
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_3_clicked()
{
    int I=0;
    //QString first_name = ui->lineEdit_3->text();
    //QString familly_name=ui->lineEdit_4->text();
    //QString pass=ui->lineEdit_5->text();
    //QString email=ui->lineEdit_6->text();
    // as real data variable
    //QDate Mydate= ui->dateEdit->date();
    //as string
    //QString dateString =Mydate.toString();
    //insert the new values into the database
    QSqlDatabase db=QSqlDatabase ::addDatabase("QMYSQL");//QSQLITE
    db.setConnectOptions();
    db.setHostName("127.0.0.1");
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("Ben3ar9a");

    if (db.open())
    {
        qDebug() << "yeah it is opene!!!!!!";
        //get the last id  !!!!!!!!!!!;
         QSqlQuery  query;
        if(query.exec("SELECT * FROM  userinfo"))
        {
            while (query.next() )
            {
                        I=query.value(0).toInt();
            }
        }
        else
        {
            qDebug () << "error"<<db.lastError().text();
        }
        //
        QString Squery="INSERT INTO userinfo (id,email,password,username,famillyname,birthday) VALUES (:id,:email,:password,:username,:famillyname,:birthday)";
        I++;
        query.prepare(Squery);
        query.bindValue(":id",I);
        query.bindValue(":email",ui->lineEdit_6->text());
        query.bindValue(":password",ui->lineEdit_5->text());
        query.bindValue(":username",ui->lineEdit_3->text());
        query.bindValue(":famillyname",ui->lineEdit_4->text());
        query.bindValue(":birthday",ui->dateEdit->date());

        if(query.exec())
        {
            qDebug () <<"record inserted";
        }
        else
        {
            qDebug () << "error"<<db.lastError().text();
        }
        qDebug()<< "close connection to mysqldatabase ";
        db.close();
    }
    else
    {
        qDebug () << "error"<<db.lastError().text();
    }

    //end database
    hide();
    wall=new WallDialog (this);
    wall->show();

    //cout<<first_name<<endl;
    //QString age=ui->dateEdit->keyPressEvent(QKeyEvent event);
}

/**
 * @brief
 *
 */
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
