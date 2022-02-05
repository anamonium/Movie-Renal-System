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

//funkcja tworzaca obiekt odpowiedniego okna i wyswietlająca go
void MainWindow::on_login_clicked()
{
    hide();
    loginWindow = new LogIn();
    loginWindow->show();
}


void MainWindow::on_signin_clicked()
{
    hide();
    sign=new SignIn();
    sign->show();
}

