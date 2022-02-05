#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrator)
{

    ui->setupUi(this);

}

//konstruktor tworzacy okno administratota na podstawie danych
//zawartych podczas logowania
Administrator::Administrator(Person *logedAdmin):

    ui(new Ui::Administrator)
{
    std::string nameSurname;
    nameSurname= logedAdmin->getName() + " " + logedAdmin->getSurname() + " !";
    QString nname;
    ui->setupUi(this);
    nname = QString::fromUtf8(nameSurname);
    ui->nameLabel->setText(nname);

}

Administrator::~Administrator()
{

    delete ui;
}

//otwiera okno do dodania filmow
void Administrator::on_buttonAddMovie_clicked()
{
    addMovieWindow = new AddMovie(this);
    addMovieWindow ->show();
}

//otwiera okno do wyswietlenia wszystkich filmow
void Administrator::on_buttonSeeAll_clicked()
{
    movieListWindow = new MovieList(this);
    movieListWindow ->show();
}

//otwiera okno do wyswitlania filmow kategoria
void Administrator::on_buttonSeeByCategory_clicked()
{

    movieLisCatWin = new MovieListCategory(this);
    movieLisCatWin -> show();
}


//otwiera okno do szukania filmow
void Administrator::on_buttonSearch_clicked()
{
    movieSearchWindow = new MovieSearch(this);
    movieSearchWindow -> show();
}

//otwiera okno do zobaczenia listy uzytkownikow
void Administrator::on_seeUsers_clicked()
{
    UserList *window = new UserList(this);
    window->show();
}

void Administrator::get_data(){

}

std::string Administrator::getName(){
    return this->name;
}
std::string Administrator::getSurname(){
    return this->surname;
}

/*funkcja "logujaca" administratora, otwiera ona plik w ktorym
  zapisane sa dane administratora i sprawdza czy haslo zostalo podane
  poprawnie, jezli nie to rzuca wyjatek*/
bool Administrator::login(std::string u_name, std::string p_word){
    bool flag = false;
    std::ifstream inFile;
    std::string line, word, temp;
    std::vector<std::string> row;
    inFile.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/adminData.csv", std::ios::in);

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

    if(flag == false)
        throw MyException("warning" , "Wrong username or password");

    return flag;
}
