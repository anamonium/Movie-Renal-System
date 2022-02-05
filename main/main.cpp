#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LogIn *logInWindow;
    SignIn *signInWindow;

    std::string operation = argv[1];
    if(argc!=2){ //sprawdzenie czy ilosc argumentow programu jest poprawna
         QApplication::quit(); //wyjscie z aplikacji
    }
    else{


        if(operation == "LogIn"){       //sprawdzenie czy argument programu jest poprawny
         logInWindow = new LogIn(); //utworzenie obiektu okna przeznaczonego do logowania
         logInWindow ->show(); //otwarcie odpowiedniego okna
         return a.exec();
        }
        else if(operation == "SignIn"){
            signInWindow = new SignIn();
            signInWindow->show();
            return a.exec();
        }
        else if(operation == "MainWindow"){
            w.show();
            return a.exec();
        }
        else{
           QApplication::quit();
        }
    }

}
