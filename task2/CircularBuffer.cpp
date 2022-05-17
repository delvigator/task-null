
#include "CircularBuffer.h"
template <typename T>
CircularBuffer<T>::CircularBuffer(int size) {
    this->size=size;
    data=new T[size];
    indexIn=0;
    indexOut=0;

}
template <typename T>
CircularBuffer<T>::~CircularBuffer() {
    delete[]data;
}
template <typename T>
int CircularBuffer<T>::pushBack(T &elem) {
    if(size==indexIn)throw "buffer is full";
    data[indexIn++]=elem;
    return 0;
}
template <typename T>
T CircularBuffer<T>::takeElem() {
    if (checkEmpty())
        throw "Buffer is empty";
    for (int i = 1; i < indexIn; ++i)
        data[i - 1] = data[i];

    --indexIn;
    return data[indexOut];
}
template <typename T>
T CircularBuffer<T>::getElem() {
    if (checkEmpty())
        throw "Buffer is empty";
    return data[indexOut];
}
template <typename T>
int CircularBuffer<T>::getSize() {
    return size;
}
template <typename T>
bool CircularBuffer<T>::checkEmpty() {
    if(indexIn==0) return true;
    return false;
}
template <typename T>
int CircularBuffer<T>::makeEmpty()  {
indexIn=0;
indexOut=0;
    return 0;
}
