#include "Iterator.h"
template <typename T>
Iterator<T>::Iterator(CircularBuffer<T> circularBuffer) {
    head=&circularBuffer.getElem();
}
template <typename T>
void Iterator<T>::start() {

}
template <typename T>
void Iterator<T>::next() {
    head=head->getElem()+1;
}