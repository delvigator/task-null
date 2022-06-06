
#include "List.h"

Deque::Deque() {
    head= nullptr;
    tail= nullptr;
    size=0;
}
Deque::DequeIter::DequeIter(Deque *deque):deque(deque) {
current= nullptr;
}

Node* Deque::DequeIter::getElem() {
    return current;
}
void Deque::DequeIter::start() {
    current=deque->head;
}

void Deque::DequeIter::next() {
    current++;
}

bool Deque::DequeIter::finish()  {
    return current==deque->tail;
}

int Deque::DequeIter::getValue() {
    return current->elem;
}

int Deque::put(int elem, Iterator *iterator) {
    std::cout<<"1\n";
    Node *temp = new Node;
    temp->elem = elem;
    if(size==0){
        std::cout<<"2\n";
        head = tail = temp;
        temp->next= nullptr;
        temp->previous= nullptr;
    }
   /*if(iterator->getElem()==head->next){
       std::cout<<"3\n";
temp->next=head;
temp->previous= nullptr;
head=temp;
   }
    if(iterator->getElem()==tail->next){
        std::cout<<"4\n";
temp->next= nullptr;
temp->previous=tail;
tail=temp;
    }
*/
    if(iterator->getElem()!=tail &&iterator->getElem()!=head && size!=0){
        std::cout<<"5\n";
        if(iterator->getElem()!= nullptr) {
            temp->next = iterator->getElem()->next;
            std::cout << "6\n";
            temp->previous = iterator->getElem();
            std::cout << "7\n";
            iterator->getElem()->next = temp;
            std::cout << "8\n";
            iterator->getElem()->next->previous = temp;
        }
        else{

        }
    }
    size++;
   return 0;
}


Deque::Iterator *Deque::begin() {
Iterator *result=new DequeIter(this);
   result->start();
   return result;

}

int Deque::del(Iterator *iterator) {
    size--;
    return 0;
}

Deque::Iterator* Deque::getFirstEntry(int elem) {
   return getIterator();
}

int Deque::getSize() {
return 0;
}

bool Deque::checkEmpty() {
    return true;
}

int Deque::makeEmpty() {
    return 0;
}

Deque::Iterator *Deque::getIterator() {
    auto*it=new Deque::DequeIter(this);
    return it;
}