#include <iostream>
#include "List.h"
int main() {
    Deque *deque=new Deque();
    auto*it=new Deque::DequeIter(deque);
    std::cout<<"it->start()\n";
    it->start();
    for(int i=0;i<10;i++){
        std::cout<<"i\n"<<i<<std::endl;
        deque->put(i,it);
        it->next();
    }

    std::cout<<"it->start()\n";
    for(int i=0;i<10;i++){
        std::cout<<it->getValue()<<std::endl;
        it->next();
    }



}