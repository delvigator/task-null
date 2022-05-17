#include <iostream>
#include <utility>
using namespace std;
class SizeException :public exception{
private:
    string m_error;
public:
    explicit SizeException(string error)
    :m_error(std::move(error))
            {

            }
};
