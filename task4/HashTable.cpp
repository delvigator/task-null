
#include "HashTable.h"

HashTable::HashTable(int n) {
    this->capacity=getPrime(n);
    table=new Deque[capacity];

}
HashTable::~HashTable() {
    table->makeEmpty();
    this->capacity=0;
}
int HashTable::insertItem(int key, int data) {
    int index= hashFunction(key);
    table[index].put(data,table[index].begin());
    return 0;
}

int HashTable::deleteItem(int key) {
    if(checkEmpty())throw ElemException("no elements with this key");
    int index = hashFunction(key);
    table[index].del(table[index].begin());
    return 0;
}

bool HashTable::checkEmpty() {
    bool result=true;
    for(int i=0;i<capacity;i++){
        if(!table[i].checkEmpty())
            result=false;
        }
    return result;
}

bool HashTable::checkPrime(int n) {
    int i;
    if (n == 1 || n == 0)
    {
        return false;
    }
    for (i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int HashTable::getPrime(int n)
{
    if (n % 2 == 0)
    {
        n++;
    }
    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}
int HashTable::hashFunction(int key)
{
    int result=key%capacity;
    return result;
}

int HashTable::toString() {
    for (int i = 0; i < capacity; i++) {
        std::cout << "index ["<<i<<"]";
        auto *it = new Deque::DequeIter(table[i]);
        it->start();
        while (!it->finish()) {
            it->next();
            std::cout << " --> " << it->getValue();

        }
        std::cout << std::endl;
    }
    return  0;
}
int HashTable::search(int data) {
    int index;
    bool fail=true;
for(int i=0;i<capacity;i++){
    auto *it=new Deque::DequeIter(table[i]);
    it->start();
    while(!it->finish()){
        it->next();
        if(it->getValue()==data) {
            index=i;
            fail=false;
        }
    }
}
    if(fail) throw ElemException("elem not found");
    return index;
}

int HashTable::makeEmpty() {
    for(int i=0;i<capacity;i++){
        table[i].makeEmpty();
    }
    return 0;
}
HashTable::Iterator::Iterator(const HashTable &hashTable):hashTable(hashTable),index(0),check(false) {

}
void HashTable::Iterator::start() {

    iter=new Deque::DequeIter(hashTable.table[index]);
    iter->start();
    iter->next();
}

int HashTable::Iterator::getValue() {
   return iter->getValue();
}

void HashTable::Iterator::next() {
    if (index != hashTable.capacity - 1) {
        if (iter->finish()) {
            index++;
            start();
        } else {
            iter->next();
        }
    }
    else check=true;
}

bool HashTable::Iterator::finish() {

    if(!check)
    return (index==hashTable.capacity&&iter->finish());
    return check;
}