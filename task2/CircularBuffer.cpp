
#include "CircularBuffer.h"
#include "Exception.cpp"
CircularBuffer::CircularBuffer(int size) {
    this->size=size;
    data=new int[size];
    indexIn=-1;
    indexOut=-1;

}

CircularBuffer::~CircularBuffer() {
    delete[]data;
    indexIn=-1;
    indexOut=-1;
}

int CircularBuffer::pushBack(int elem) {
    if(indexOut==(indexIn+1)%size)throw Exception("is full");
    if(indexOut == -1) indexOut = 0;
    indexIn=(indexIn+1)%size;
    data[indexIn]=elem;
    return 0;
}

int CircularBuffer::takeElem() {

    if (isEmpty())
        throw Exception("is empty");
   int elem = data[indexOut];
    if(indexOut == indexIn) {
        indexIn = -1;
        indexOut = -1;
    }
    else {
        indexOut=(indexOut+1) % size;
    }
    return elem;
}

int CircularBuffer::getElem() {
    if (isEmpty())
        throw Exception("is empty");
    return data[indexOut];
}

int CircularBuffer::getSize()const {
    return size;
}

bool CircularBuffer::isEmpty() const {
    if(indexOut==-1) return true;
    return false;
}

int CircularBuffer::makeEmpty()  {
indexIn=-1;
indexOut=-1;
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
    return current==circularBuffer.data+circularBuffer.indexOut+circularBuffer.indexIn+1;
}

int CircularBuffer::Iterator::getValue() const {
    return *current;
}
