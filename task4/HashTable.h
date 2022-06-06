#include <iostream>
#include "ElemException.cpp"
#include <list>
#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H


class HashTable {
private:
    int capacity;
   std::list<int> *table;
public:
HashTable(int n);
~HashTable();
int hashFunction(int key);
int insertItem(int key,int data);
static bool checkPrime(int n);
static int getPrime(int n);
int deleteItem(int key);
int search(int data);
int makeEmpty();
bool checkEmpty();
int toString();
    class Iterator
    {
    private:
        const HashTable& hashTable;
        int index;
        std::list<int>::iterator iter;

    public:
        explicit Iterator(const HashTable& hashTable);
        void start();
        void next();
        bool finish();
        int getValue();
    };
};


#endif //TASK4_HASHTABLE_H
