#include <iostream>
#include "CircularBuffer.h"
int main() {
    CircularBuffer queue(3);
    queue.pushBack(0);
    queue.pushBack(1);
    queue.pushBack(2);
    std::cout << queue.isEmpty();
    std::cout << queue.getElem();
    queue.takeElem();
    std::cout << queue.getElem();
    queue.takeElem();
    std::cout << queue.getElem();
    queue.takeElem();
    CircularBuffer queue1(3);
    queue1.pushBack(0);
    queue1.pushBack(1);
    queue1.pushBack(2);
    CircularBuffer::Iterator it(queue1);
    it.start();
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << it.getValue() << " ";
        it.next();
    }
    std::cout << it.finish();
    queue.makeEmpty();
    std::cout << queue.isEmpty() << std::endl;
    queue.pushBack(33);
    std::cout << queue.takeElem() << std::endl;
    std::cout << queue.isEmpty();

}
