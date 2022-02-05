#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signin.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();  //obsluga przycisku "log in"
    void on_signin_clicked(); //obsluga przycisku "sign in"

private:
    Ui::MainWindow *ui;
    SignIn *sign;
    LogIn *loginWindow;
};
#endif // MAINWINDOW_H
