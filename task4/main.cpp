#include <iostream>
#include "HashTable.h"
int main() {
    HashTable table(9);
    table.insertItem(0,1);
    table.insertItem(0,4);
    table.insertItem(1,4);
    table.insertItem(1,4);
    table.insertItem(0,5);
    table.insertItem(200,50);
    table.insertItem(2,50);
    table.toString();
    std:: cout<<"\ndeleteItem(0)\n";
    table.deleteItem(0);

    table.toString();
   std:: cout<<"\ntable.search(5)\n"<<table.search(5);
    std:: cout<<"\nmakeEmpty()\n";
   table.makeEmpty();
    table.toString();
    std:: cout<<"\ncheckEmpty()\n"<<table.checkEmpty();
    std:: cout<<"\nstart\n";
    table.insertItem(0,1);
    table.insertItem(0,3);
    table.insertItem(1,5);
    table.insertItem(1,4);
    table.insertItem(0,2);
    table.insertItem(200,6);
    table.insertItem(2,7);
    table.insertItem(10,8);
    table.toString();
    HashTable::Iterator iterator(table);
    iterator.start();
     while (!iterator.finish()){
         std::cout << iterator.getValue() << " ";
         iterator.next();
     }
    //for (int i = 0; !iterator.finish(); i++)
    //{
    //    std::cout << iterator.getValue() << " ";
    //    iterator.next();
   // }
   // std::cout<<iterator.finish();
    return 0;
}
