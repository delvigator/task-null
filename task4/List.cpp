#include "List.h"

Deque::Deque() {
    size=0;
    buf= new Node();
    buf->next = buf;
    buf->previous = buf;


}
Deque::~Deque() {
    if(!checkEmpty()) {
        makeEmpty();
    }
    delete buf;
    size=0;
    buf = nullptr;
}
Deque::Deque(const Deque &deque) {
    buf = new Node;
    const Node* temp = deque.buf->next;
    Node* first = buf;
    Node* sec;
    size=deque.size;
    while (temp != deque.buf)
    {
        sec = new Node;
        first->next = sec;
        sec->previous = first;
        sec->elem = temp->elem;
        first = first->next;
        temp = temp->next;
    }
    buf->previous = first;
    first->next = buf;
}
Deque::Deque(Deque &&deque) {
    buf=deque.buf;
    size=deque.size;
    deque.buf = nullptr;
    deque.size = 0;
}
Deque::DequeIter::DequeIter(Deque &deque):buf(deque.getBuf()),num(-1),size(deque.getSize()) {

}

Node* Deque::DequeIter::getElem() {
    return current;
}
void Deque::DequeIter::start() {
    current=buf;
    num=-1;
}

void Deque::DequeIter::next() {
   current=current->next;
   num++;
}

bool Deque::DequeIter::finish()  {
if(num>=size-1) return true;
return false;
}

int Deque::DequeIter::getValue() {
    return current->elem;
}

int Deque::put(int elem, Iterator *iterator) {

    Node* temp = new Node();
    temp->elem=elem;
    if (size == 0) {
        temp->next = buf;
        temp->previous = buf;
        buf->next = temp;
        buf->previous = temp;
        size++;
    }
    else
    {
        Node* node= iterator->getElem();
        node->next->previous = temp;
        temp->next = node->next;
        temp->previous = node;
        node->next = temp;
        size++;
    }
   return 0;
}


Deque::Iterator *Deque::begin() {
Iterator *result=new DequeIter(*this);
   result->start();
   result->next();
   return result;

}

Deque::Iterator *Deque::end() {
    Iterator *result=new DequeIter(*this);
    result->finish();
    return result;
}
int Deque::del(Iterator *iterator) {
    Node* node = iterator->getElem();
    node->next->previous = node->previous;
    node->previous->next = node->next;
    delete node;
    size--;
    return 0;
}

Node *Deque::getBuf() {
    return buf;
}
Deque::Iterator* Deque::getFirstEntry(int elem) {
    Node* node = buf->next;
    int i = 0;
    while (node != buf)
    {
        i++;
        if (node->elem == elem)
        {
            break;
        }
        node = node->next;
    }
    if (node == buf)
    {
        return nullptr;
    }
    auto*it=new Deque::DequeIter(*this);
    it->start();
    for (int j = 0; j < i; j++)
    {
        it->next();
    }
    return it;
}

int Deque::getSize() {
return size;
}

bool Deque::checkEmpty() {
    if(size==0) return true;
    return false;
}

int Deque::makeEmpty() {
    Node* temp = buf;
    Node* node = nullptr;
    while (temp->next != buf)
    {
        temp = temp->next;
        delete node;
        node = temp;
        size--;
    }
    delete node;
    return 0;
}


Deque &Deque::operator=(const Deque &o) {
    if (this != &o)
    {
        buf = new Node;
        const Node* tmp = o.buf->next;
        Node* p = buf;
        Node* n;
        while (tmp != o.buf)
        {
            n = new Node;
            p->next = n;
            n->previous = p;
            n->elem = tmp->elem;
            p = p->next;
            tmp = tmp->next;
        }
        buf->previous = p;
        p->next = buf;
    }
    return (*this);

}

Deque &Deque::operator=(Deque &&o)  noexcept {
    if (this != &o)
    {
        makeEmpty();
        buf = o.buf;
        size = o.size;
        o.buf = nullptr;
        o.size = 0;
    }
    return (*this);
}

