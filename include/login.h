#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "user.h"
#include "administrator.h"
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <fstream>
#include <vector>



namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
     bool login(std::string username,std::string password);
     bool login(std::string password);

private slots:
    void on_pushButton_clicked(); //obsluga przycisku "log in"
    void on_goBackMainSign_clicked(); //obsluga przycisku "go back"

private:
    Ui::LogIn *ui;
    User *userWindow;
    Administrator *adminWindow;
};

#endif // LOGIN_H
