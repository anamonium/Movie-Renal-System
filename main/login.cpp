#include "login.h"
#include "ui_login.h"
#include <string>
#include <sstream>
#include "mainwindow.h"


LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    ui->login_password->setEchoMode(QLineEdit::Password);
}

LogIn::~LogIn()
{
    delete ui;
}

/*pobiera dane z okien przeznaczonych do wypelnienia
  i sprawdza czy sa one poprawne, jezeli twak otwiera okno dla
  uzytkownika badz administratora*/
void LogIn::on_pushButton_clicked()
{

    Person *userLogin = new User();
    Person *adminLogin = new Administrator();
    std::string u_name, p_sswd;
    u_name = (ui->login_username->text()).toUtf8().constData(); //pobranie z pola przeznaczonego do pisania i przekonwertowanie tej wartosci z QStringa do stringa
    p_sswd = (ui->login_password->text()).toUtf8().constData();

    if(u_name == "administrator"){
        try{
            adminLogin->login(u_name, p_sswd);

            adminWindow = new Administrator(adminLogin); //utworzenie nowego okna
            hide();
            adminWindow -> show();

        }
        catch(const std::exception &exc){
            std::cerr<< exc.what(); //wyswietlenie tekstu wyjatku
            QMessageBox::warning(this, "Login", "Username or password not correct"); //wyswietlenie okienka z informacja
            ui->login_password->clear(); //wyczyszczenie pol przeznaczonych do pisania
            ui->login_username->clear();
        }
    }
    else{
        try{
            userLogin->login(u_name, p_sswd);

            userWindow = new User(userLogin);
            hide();
            userWindow->show();

        }
        catch(const std::exception &exc){
            std::cerr<< exc.what();
            QMessageBox::warning(this, "Login", "Username or password not correct");
            ui->login_password->clear();
            ui->login_username->clear();
        }
    }
}


//pozwala powrocic do glownego okna
void LogIn::on_goBackMainSign_clicked()
{
    MainWindow *newWindow = new MainWindow();
    newWindow->show();
    hide();
}
