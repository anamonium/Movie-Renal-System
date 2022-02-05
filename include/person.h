#ifndef PERSON_H
#define PERSON_H
#include <QString>

struct person{
    std::string usNm, nm, sNm;
};

class Person{
protected:
    std::string username;
    std::string password;

public:
    virtual bool login(std::string username, std::string passoword)=0; //witrualne metody
    virtual std::string getName()=0;
    virtual std::string getSurname()=0;

};
#endif // PERSON_H
