
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int size) {
    this->size=size;
    data=new int[size];
    indexIn=0;
    indexOut=0;

}

CircularBuffer::~CircularBuffer() {
    delete[]data;
}

int CircularBuffer::pushBack(int elem) {
    if(size==indexIn)throw exception();
    data[indexIn++]=elem;
    return 0;
}

int CircularBuffer::takeElem() {
    if (isEmpty())
        throw exception();
    for (int i = 1; i < indexIn; ++i)
        data[i - 1] = data[i];

    --indexIn;
    return data[indexOut];
}

int CircularBuffer::getElem() {
    if (isEmpty())
        throw exception();
    return data[indexOut];
}

int CircularBuffer::getSize()const {
    return size;
}

bool CircularBuffer::isEmpty() const {
    if(indexIn==0) return true;
    return false;
}

int CircularBuffer::makeEmpty()  {
indexIn=0;
indexOut=0;
    return 0;
}

CircularBuffer::Iterator::Iterator(const CircularBuffer &circularBuffer) :circularBuffer(circularBuffer){

}

void CircularBuffer::Iterator::start() {
    current=circularBuffer.data+circularBuffer.indexOut;
}

void CircularBuffer::Iterator::next() {
    current++;
}

bool CircularBuffer::Iterator::finish() const {
    return current==circularBuffer.data+circularBuffer.indexOut+circularBuffer.indexIn;
}

int CircularBuffer::Iterator::getValue() const {
    return *current;
}
