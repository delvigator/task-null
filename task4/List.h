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
    virtual Node* getBuf()=0;
 virtual Iterator* end()=0;
 virtual bool checkEmpty()=0;
 virtual int getSize()=0;

 virtual Iterator* begin()=0;


};
class Deque:public List{

private:
    Node *buf;
    int size;
public:
    explicit Deque();
    Deque(const Deque&deque);
    Deque( Deque&&deque);
    ~Deque();
    class DequeIter:public Iterator{
    private:
        Node *buf;
        Node *current;
        int num;
        int size;
    public:
        explicit DequeIter(Deque &deque);
        void start() override;
        void next() override;
        bool finish() override;
        int getValue() override;
        Node* getElem() override;


    };
int put(int elem,Iterator* iterator) override;
int del(Iterator *iterator);

Iterator* getFirstEntry(int elem);
int makeEmpty();
bool checkEmpty() override;
int getSize() override;
Iterator* begin() override;
Iterator* end();
Node* getBuf();

Deque& operator=(const Deque &o);
Deque &operator =( Deque &&o) noexcept;
};

#endif //TASK3_LIST_H
