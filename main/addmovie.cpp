#include "addmovie.h"
#include "ui_addmovie.h"

/*przeciazenie operatora '+' , ktory dodaje element
  na koniec kontenera
  do definicji użyto szablonów*/
template<typename T>
std::vector<T> operator + (std::vector<T> A, const movie film){
    A.push_back(film);
    return A;
}

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
}

AddMovie::~AddMovie()
{
    delete ui;
}

/*funkcja ktora odczytuje wartości które zostały umieszczone
   w odpowiednich polach przez użytkownika, zwraca ona obiekt
   struktury movie */
movie AddMovie:: addMovie(){
    movie film;

    film.title = (ui->addMovieTitle->text()).toUtf8().constData();
    film.director = (ui->addMovieDirector->text()).toUtf8().constData();
    film.category = (ui->addMovieCategory->currentText()).toUtf8().constData();
    film.length = ui->addMovieLength->value();
    film.year = ui->addMovieYear->value();
    film.price = ui->addMoviePrice->value();

    return film;
}


/*funkcja która dodaje film do pliku po wciśnięciu odpowiedniego przycisku*/
void AddMovie::on_addMovie_clicked()
{
    std::ofstream File;
    movie film = addMovie();
    movie filmTmp = addMovie();

    try{
        checkInput();

        try{
            checkInput(filmTmp);

            File.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/movieList.csv", std::ios::out | std::ios::app);
            File<<film.title<<","<<film.director<<","<<film.category<<","<<film.length<<","<<film.year<<","<<film.price;
            File<<"\n";
            File.close();
            QMessageBox::information(this,"AddMovie","Your movie has been added succesfully");
            ui->addMovieTitle->clear();
            ui->addMovieDirector->clear();
        }
        catch(const std::exception &exc){
            std::cerr<< exc.what();
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Test", "This movie already exists\nDo you want to add the same?",
                                  QMessageBox::Yes| QMessageBox::No);

            if(reply == QMessageBox::Yes){
                File.open("/Users/anne/Desktop/projekcic/build-nienazwany-Qt_6_2_2_for_macOS-Debug/movieList.csv", std::ios::out | std::ios::app);
                File<<film.title<<","<<film.director<<","<<film.category<<","<<film.length<<","<<film.year<<","<<film.price;
                File<<"\n";
                File.close();
                QMessageBox::information(this,"AddMovie","Your movie has been added succesfully");
                ui->addMovieTitle->clear();
                ui->addMovieDirector->clear();

            }
            else{
                QMessageBox::information(this,"AddMovie","Your movie has not been added");
                ui->addMovieTitle->clear();
                ui->addMovieDirector->clear();
            }

        }
    }
    catch(const std::exception &exc){
        std::cerr<< exc.what();
        QMessageBox::warning(this, "Add Movie" , "Every box must contain data");
        ui->addMovieTitle->clear();
        ui->addMovieDirector->clear();
    }
}

/*funkcja przyjumjaca w argumencie obiekt struktury movie
   sprawdza ona czy dany tytul istnieje juz w bazie danych
   jezeli istnieje to rzuca ona wyjatek*/
bool AddMovie::checkInput(movie film){
    bool flag = false;

    std::vector<movie> mList;
    std::vector<movie>::iterator x;
    readMovie(mList);
    std::string title, word;

    title = film.title;
    std::for_each(title.begin(), title.end(), [](char &c){ //każda litera tytułu zostaje sprowadzona do małej litery
        c = ::tolower(c);                                   //aby zapobiec tym samym tytułom tylko o różnych rozmiarach liter
    });

    for(x = mList.begin(); x!=mList.end(); ++x){

        word = (*x).title;
        std::for_each(word.begin(), word.end(), [](char &d){
            d = ::tolower(d);
        });

        if(word == title){
            throw MyException("warning" , "This title already exists");
            flag = true;
        }
    }

    return flag;
}

/*funkcja nie przyjmująca argumentów, sprawdza ona czy wszystkie pola
  przeznaczone do uzupełniania niezbędnych informacji o danym filmie
  zostały uzupełnione, jeżeli nie to rzuca ona wyjątek*/
bool AddMovie::checkInput(){
    bool flag = false;
    std::string title, director;

    title = (ui->addMovieTitle->text()).toUtf8().constData();
    director = (ui->addMovieDirector->text()).toUtf8().constData();

    if(title == "" || director == ""){
        throw MyException("warning" , "Input cannot be empty");
        flag = true;
    }
    return flag;
}
