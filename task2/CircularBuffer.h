#ifndef TASK2_CIRCULARBUFFER_H
#define TASK2_CIRCULARBUFFER_H

#include <iostream>
using namespace std;
template <typename T>
class CircularBuffer {
private:
    T*data;
int size;
int indexIn;
int indexOut;
public:
CircularBuffer(int size);
~CircularBuffer();
int pushBack(T &elem) const;
T takeElem();
T getElem();
int getSize() const;
int makeEmpty() const;
bool checkEmpty() const;

};


#endif //TASK2_CIRCULARBUFFER_H
