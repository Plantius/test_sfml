#ifndef ERROR_H
#define ERROR_H
#include <iostream>

class textError : public std::exception
{
    private:
        std::string error;
    public:
        textError(const std::string err) {this->error = err;};
        virtual const char* what() const throw();
};

#endif