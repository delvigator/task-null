#include <iostream>
using namespace std;



class ElemException: public exception{
private:
    string m_error;
public:
    ElemException(string error)
            :m_error(error)
    {

    }
};