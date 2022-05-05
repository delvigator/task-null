#include <iostream>
using namespace std;



class WeightException: public exception{
private:
    string m_error;
public:
    WeightException(string error)
            :m_error(error)
    {

    }
};