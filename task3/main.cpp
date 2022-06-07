#include <iostream>
#include "List.h"
int main() {
    Deque deque;
    auto *it=new Deque::DequeIter(deque);
    it->start();
   for(int i=0;i<10;i++){
        deque.put(i,it);
        it->next();
    }
    std::cout<<"\nit->start()\n";
    it->start();
    for(int i=0;i<10;i++){
        it->next();
        std::cout<<it->getValue()<<std::endl;
    }
    std::cout<<"\nit->finish()\n"<<it->finish();
    std::cout<<"\ndeque.makeEmpty()\n";
    deque.makeEmpty();
    std::cout<<"\ncheckEmpty()\n"<<deque.checkEmpty();
    it->start();
deque.put(7,it);
it->next();
deque.put(4,it);
it->next();
deque.put(7,it);
    it->next();
    std::cout<<"\ngetFirstEntry(7)\n"<<deque.getFirstEntry(7)->getValue();
    std::cout<<"\nbegin\n"<<deque.begin()->getValue()<<std::endl;

    Deque deque1=deque;
    auto *it1=new Deque::DequeIter(deque1);
    it1->start();
    while(!it1->finish()){
        it1->next();
        std::cout<<it1->getValue()<<std::endl;
    }
return 0;
}