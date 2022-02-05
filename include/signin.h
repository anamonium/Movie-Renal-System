#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include "user.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "myexception.h"


namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();
    int checkIfExists(std::string username); //funkcja sprawdzajaca czy uzytkowink juz istnieje
    bool checkInput(); //funkcja sprawdzajaca czy wszystkie pola sa wpisane

signals:
    void backLogIn();

private slots:


    void on_commandLinkButton_clicked(); //obsluga przyciusku "go_back"

    void on_push_button_signin_2_clicked(); //obsluga przyciksu "sign_in"

private:
    Ui::SignIn *ui;


};

#endif // SIGNIN_H
