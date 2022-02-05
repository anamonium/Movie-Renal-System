#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::User(Person *logedUser): ui(new Ui::User){
     ui->setupUi(this);
     std::string nameSur;
     nameSur= logedUser->getName() + " " + logedUser->getSurname() + " !";
     QString nameSu;
     nameSu = QString::fromUtf8(nameSur);
     ui->name->setText(nameSu);

}

User::~User()
{
    delete ui;
}

std::string User::getName(){
    return this->name;
}

std::string User::getSurname(){
    return this->surname;
}

void User:: setUsername(std::string newUsername){
    this->username=newUsername;
}

void User:: setPassword(std::string newPassword){
    this->password = newPassword;
}

void User:: setAge(int age){
    this->age = age;
}

void User:: setName(std::string newName){
    this->name=newName;
}

void User:: setSurname(std::string newSurname){
    this->surname=newSurname;
}

void User::get_data(){

}

std::string User:: getUsername(){
    return username;
}

std::string User:: toString(){
    return username + "," + password + "," + name + "," + surname;
}

//funkcja zapisująca do pliku dane o użytkowniku
void User:: SignIn(){
    std::ofstream outFile; //otwarcie pliku w trybie do pisania
    outFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/userList.csv", std::ios::app);
    outFile<<username<<","<<password<<","<<name<<","<<surname<<","<<age; //pisanie do pliku
    outFile<<"\n";
    outFile.close(); //zakmkniecie pliku
}

void User::on_buttonSeeAll_clicked()
{
    movieListWindow = new MovieList(this);
    movieListWindow ->show();
}


void User::on_seeByCategory_clicked()
{
    movieLisCatWin = new MovieListCategory(this);
    movieLisCatWin -> show();
}


void User::on_searchForMovie_clicked()
{
    movieSearchWindow = new MovieSearch(this);
    movieSearchWindow -> show();
}

/*funkcja która sprawdza czy podane dane przez uzytkownika do logowania
  są poprawne */
bool User::login(std::string u_name, std::string p_word){
    bool flag = false;
    std::ifstream inFile; //otwarcie pliku w trybie do odczytu
    std::string line, word, temp; //zmienie pomocnicze
    std::vector<std::string> row; //kontener przechowujacy dane o uzytkowniku
    inFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/userList.csv", std::ios::in);

    if(!inFile){
        QMessageBox::warning(this, "logIn", "File didnt open");
    }

    while(getline(inFile, line)){
        row.clear();

        std::stringstream s(line);

        while(std::getline(s, word, ',')){
            row.push_back(word);
        }

        if(row[0] == u_name && row[1] == p_word){
            name = row[2];
            surname = row[3];

            flag = true;
        }
    }
    inFile.close();
    if(flag==false)
        throw MyException("warning" , "Wrong username or password");

   return flag;
}


/*funkcja zwraca kontener w którym znajdują się dane o użytkownikach: imię, nazwisko, username
  dane te odczytuje z pliku*/
std::vector <person>User:: getList(){
    std::vector<person> userList;
    std::string line, word, temp;
    std::vector<std::string> row;
    person usrTemp;
    std::ifstream inFile;
    inFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/userList.csv", std::ios::in);

    if(!inFile){
        QMessageBox::warning(this, "logIn", "File didnt open");
    }

    while(getline(inFile, line)){
        row.clear();

        std::stringstream s(line);

        while(std::getline(s, word, ',')){
            row.push_back(word);
        }
        usrTemp.nm = row[2];
        usrTemp.sNm=row[3];
        usrTemp.usNm=row[0];

        userList.push_back(usrTemp);
    }
    inFile.close();

    return userList;
}
