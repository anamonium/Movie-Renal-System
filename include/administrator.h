#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>
#include "person.h"
#include "movie.h"
#include "addmovie.h"
#include "movielist.h"
#include "movielistcategory.h"
#include "moviesearch.h"
#include "userlist.h"
#include "myexception.h"

namespace Ui {
class Administrator;
}

class Administrator : public QDialog, public Person
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    Administrator(Person *logedAdmin);
    ~Administrator();
    void get_data();
    bool login(std::string username, std::string passoword);
    std::string getName();
    std::string getSurname();




private slots:
    void on_buttonAddMovie_clicked();

    void on_buttonSeeAll_clicked();

    void on_buttonSeeByCategory_clicked();

    void on_buttonSearch_clicked();

    void on_seeUsers_clicked();



private:
    Ui::Administrator *ui;
    AddMovie *addMovieWindow;
    MovieList *movieListWindow;
    MovieListCategory *movieLisCatWin;
    MovieSearch *movieSearchWindow;

    std::string name;
    std::string surname;
};
#endif // ADMINISTRATOR_H

