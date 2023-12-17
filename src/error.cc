#include "error.h"

const char* textError::what() const throw()
{
    return this->error.c_str();
} // what
