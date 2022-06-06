
#include "HashTable.h"

HashTable::HashTable(int n) {
    this->capacity=getPrime(n);
    table=new std::list<int>[capacity];

}
HashTable::~HashTable() {
    table->clear();
    this->capacity=0;
}
int HashTable::insertItem(int key, int data) {
    int index= hashFunction(key);
    table[index].push_back(data);
    return 0;
}

int HashTable::deleteItem(int key) {
    if(checkEmpty())throw ElemException("no elements with this key");
    int index = hashFunction(key);
    table[index].erase(table[index].begin());
    return 0;
}

bool HashTable::checkEmpty() {
    bool result=true;
    for(int i=0;i<capacity;i++){
        if(!table[i].empty())
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
    for(int i=0;i<capacity;i++){
        std:: cout << "table[" << i << "]";
        for (auto x : table[i])
            std::cout << " --> " << x;
        std:: cout << std::endl;
    }
}
int HashTable::search(int data) {
    int index;
    bool fail=true;
for(int i=0;i<capacity;i++){
    for (auto x : table[i]){
        if(x==data) {
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
        table[i].clear();
    }
    return 0;
}
HashTable::Iterator::Iterator(const HashTable &hashTable):hashTable(hashTable) {

}
void HashTable::Iterator::start() {
    iter = hashTable.table[index].begin();

}

int HashTable::Iterator::getValue() {

    if (iter == hashTable.table[index].end() && index != (hashTable.capacity - 1)) {
    next();
    getValue();
}
    if(finish()) {
        return 0;
    }
   return *iter;
}

void HashTable::Iterator::next() {
    if (!finish()) {
        if (iter == hashTable.table[index].end()) {
            index++;
            iter = hashTable.table[index].begin();
        } else {
            iter++;
        }
    }
}

bool HashTable::Iterator::finish() {
    return (index==(hashTable.capacity-1)&&(iter==hashTable.table[index].end()));
}