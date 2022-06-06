#include <iostream>




class Exception: public std::exception{
private:
    std::string m_error;
public:
    Exception(std::string error)
            :m_error(error)
    {

    }
};