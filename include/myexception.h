#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

class MyException :public std::exception
{
private:
    std::string mmessage;
    const std::string ttype;
    static std::string makeMessage(const std::string &type,
                                   const std::string &message);
public:
    MyException(const std::string &type,
                const std::string &message);
    const char *what() const throw();
    const char *what(std::string &rType) const throw();
};

#endif // MYEXCEPTION_H
