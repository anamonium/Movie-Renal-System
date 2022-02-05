#include "signin.h"
#include "ui_signin.h"
#include <fstream>
#include "mainwindow.h"

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_commandLinkButton_clicked()
{
    MainWindow *newwindow= new MainWindow();
    hide();
    newwindow->show();
}


/*funkcja tworząca nowy obiekt User i przypisująca jego polom odpowiednia dane
  wprowadzone przez użytkownika
  sprawdza ona czy zostałę poprawnie wprowzdzone, jeśli tak dane są zapisane do pliku
  a pola czyszczone
  w przeciwnym wypadku pola są czyszczone a na ekranie zostaje wyświetlona odpowiednia informacja*/
void SignIn::on_push_button_signin_2_clicked()
{
    try{
        checkInput();
        User usr;
        usr.setUsername((ui->lineEdit_si_username_2->text()).toUtf8().constData());
        usr.setPassword((ui->lineEdit_si_Password_2->text()).toUtf8().constData());
        usr.setName((ui->lineEdit_si_name_2->text()).toUtf8().constData());
        usr.setSurname((ui->lineEdit_si_surname_2->text()).toUtf8().constData());
        usr.setAge(ui->spinBox_age_2->value());

        std::string tmp = usr.getUsername();

        try{
            checkIfExists(tmp);

            usr.SignIn();
            QMessageBox::information(this, "SignIn", "Your account has been succesfully created");
            ui->lineEdit_si_Password_2->clear();
            ui->lineEdit_si_username_2->clear();
            ui->lineEdit_si_name_2->clear();
            ui->lineEdit_si_surname_2->clear();
        }
        catch(const std::exception &exc){
            std::cerr<< exc.what();
            QMessageBox::warning(this, "SignIn", "This account already exists");
            ui->lineEdit_si_Password_2->clear();
            ui->lineEdit_si_username_2->clear();
            ui->lineEdit_si_name_2->clear();
            ui->lineEdit_si_surname_2->clear();
        }
    }
    catch(const std::exception &exc){
        std::cerr<< exc.what();
        QMessageBox::warning(this, "Sign In","Type correct data\nUsername cannot have any white spaces\nEvery box must contain data");
        ui->lineEdit_si_Password_2->clear();
        ui->lineEdit_si_username_2->clear();
        ui->lineEdit_si_name_2->clear();
        ui->lineEdit_si_surname_2->clear();
    }


}

//funkcja sprawdzająca czy w bazie danych znajduje się już użytkownik o takiej nazwie użytkowika
int SignIn ::checkIfExists(std::string username){
    User usr;
    std::ifstream inFile;
    std::string line, word, temp;
    std::vector<std::string> row;
    inFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/userList.csv", std::ios::in);

    if(!inFile){
        QMessageBox::warning(this, "SignIn", "File didnt open");
    }

    while(getline(inFile, line)){
        row.clear();

        std::stringstream s(line);

        while(std::getline(s, word, ',')){
            row.push_back(word);
        }

        if(row[0] == username){
            throw MyException("warning" , "Username already exists");
            return 0;
        }
    }
    inFile.close();
    return 1;
}


/*Funkcja sprawdzająca czy użytkownik poprawnie wprowadził dane
  tzn., czy żadne pole nie jest puste oraz czy nazwa użytkownika nie
  zawiera w sobie żadnej spacji*/
bool SignIn:: checkInput(){
    bool flag = false;
    std::string u_name, p_word, n_me, s_name;
    u_name = (ui->lineEdit_si_username_2->text()).toUtf8().constData();
    p_word = (ui->lineEdit_si_Password_2->text()).toUtf8().constData();
    n_me = (ui->lineEdit_si_name_2->text()).toUtf8().constData();
    s_name = (ui->lineEdit_si_surname_2->text()).toUtf8().constData();

    if(u_name == "" || p_word == "" || n_me == "" || s_name == ""){
        flag = true;
    }

    for (int i=0; i<u_name.length(); ++i){
        if(std::isspace(u_name[i]))
            flag = true;
    }

    if(flag == true)
        throw MyException("warning" , "Wrong input");

    return flag;

}

