

#ifndef TASK1_DINAMICARRAYINTEGERNUMBERS_H
#include <iostream>
#include <cstring>
#include "SizeException.cpp"
using namespace std;
class DynamicArray{

private:
    int *array;
    int size;
public:
    DynamicArray();
    DynamicArray(int size);
    DynamicArray(int size,int n);
    DynamicArray(const DynamicArray &n);
    DynamicArray(DynamicArray &&n);
    ~DynamicArray();
    int getSize();
   int& operator[](int index);
   int resize(int newSize);
   bool operator==(const DynamicArray& arrayN);
   bool operator!=(const DynamicArray& arrayN);
    bool operator<(const DynamicArray& arrayN);
    bool operator>(const DynamicArray& arrayN);
    bool operator<=(const DynamicArray& arrayN);
    bool operator>=(const DynamicArray& arrayN);
    DynamicArray operator+( DynamicArray &array1);
DynamicArray &operator=(const DynamicArray &arrayN);
   DynamicArray &operator=( DynamicArray &&arrayN) noexcept ;
};
ostream &operator<<(ostream &out,DynamicArray &dynamicArray);
istream& operator>>(istream &in,DynamicArray &dynamicArray);

#define TASK1_DINAMICARRAYINTEGERNUMBERS_H

#endif //TASK1_DINAMICARRAYINTEGERNUMBERS_H
