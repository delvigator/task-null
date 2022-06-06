#include <iostream>

#ifndef TASK3_LIST_H
#define TASK3_LIST_H

struct Node{
int elem;
Node *next;
Node *previous;

};

class List {

public:
    class Iterator{
    public:
        virtual void start()=0;
        virtual void next()=0;
        virtual bool finish()=0;
        virtual int getValue()=0;
        virtual Node* getElem()=0;
    };
 virtual int put(int elem,Iterator* iterator)=0;
 virtual int del(Iterator* iterator)=0;
 virtual Iterator* getFirstEntry(int elem)=0;
 virtual int makeEmpty()=0;
 virtual bool checkEmpty()=0;
 virtual int getSize()=0;
 virtual Iterator* begin()=0;

   virtual Iterator *getIterator()=0;
};
class Deque:public List{

private:
    Node *head;
    Node *tail;
    int size;
public:
    explicit Deque();
    class DequeIter:public Iterator{
    private:
        Deque *deque;
        Node *current;
    public:
        explicit DequeIter(Deque *deque);
        void start() override;
        void next() override;
        bool finish() override;
        int getValue() override;
        Node* getElem() override;


    };
int put(int elem,Iterator* iterator);
int del(Iterator *iterator);
Iterator* getFirstEntry(int elem);
int makeEmpty();
bool checkEmpty();
int getSize();
Iterator* begin();

Iterator *getIterator();
};

#endif //TASK3_LIST_H
