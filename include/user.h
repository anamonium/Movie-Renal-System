#ifndef USER_H
#define USER_H

#include <QDialog>
#include "person.h"
#include <fstream>
#include "movielist.h"
#include "movielistcategory.h"
#include "moviesearch.h"
#include "myexception.h"


namespace Ui {
class User;
}


class User : public QDialog, public Person
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    explicit User(Person *logedUser);

    void get_data();
    void setName(std::string newName);
    void setSurname(std::string newSurname);
    void setAge(int age);
    void setUsername(std::string newUsername);
    void setPassword(std::string newPassword);
    std::string getUsername();
    std::string getName();
    std::string getSurname();
    std::string toString();
    void SignIn(); //funkcja zapisujaca do pliku dane o uzytkowinkach
    bool login(std::string username, std::string passoword); //funkcja pozwalajaca sie zalogowac
    std::vector <person> getList(); //funkcja zwracajaca vector z uzytkownikami


private slots:
    void on_buttonSeeAll_clicked();

    void on_seeByCategory_clicked();

    void on_searchForMovie_clicked();

private:
    Ui::User *ui;

    std::string name;
    std::string surname;
    int age;
    MovieList *movieListWindow;
     MovieListCategory *movieLisCatWin;
     MovieSearch *movieSearchWindow;
};

#endif // USER_H
