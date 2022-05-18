#ifndef TASK2_CIRCULARBUFFER_H
#define TASK2_CIRCULARBUFFER_H

#include <iostream>
using namespace std;

class CircularBuffer {
private:
    int *data;
int size;
int indexIn;
int indexOut;
public:
explicit CircularBuffer(int size);
~CircularBuffer();
int pushBack(int elem);
int takeElem();
int getElem();
int getSize() const;
int makeEmpty();
bool isEmpty() const;
    class Iterator
    {
    private:
        const CircularBuffer& circularBuffer;
        int *current;
    public:
        explicit Iterator(const CircularBuffer& circularBuffer);
        void start();
        void next();
        bool finish() const;
        int getValue() const;
    };

};


#endif //TASK2_CIRCULARBUFFER_H
