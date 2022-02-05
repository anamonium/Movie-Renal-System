#include "myexception.h"


MyException::MyException(const std::string &type,
                         const std::string &message):
    mmessage(makeMessage(type, message)), ttype(type){};

const char *MyException::what() const throw(){
    return mmessage.c_str();
}

const char *MyException::what(std::string &rType) const throw(){
    rType = ttype;
    return mmessage.c_str();
}

//funckja zwraca stringa ktory informuje
//ktory wyjatek nastapil (definiowane przez programiste)
std::string MyException::makeMessage(const std::string &type, const std::string &message){
    std::string s;

    s = "Exception! " + type + "\n" + "Message: " + message +"\n\n";

    return s;
}
