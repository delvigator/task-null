#include "CircularBuffer.h"
#ifndef TASK2_ITERATOR_H
#define TASK2_ITERATOR_H

template <typename T>
class Iterator{
private:
    T *head;
public:
    Iterator(CircularBuffer<T> circularBuffer);
    void start();
    void next();
    bool finish();
    int getValue();
};


#endif //TASK2_ITERATOR_H
