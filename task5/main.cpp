#include <iostream>
#include "Tree.h"
int main() {
   Tree t;
   int i=0;
   int *arr=new int [5];
   arr[0]=0;
   arr[1]=1;
   arr[2]=0;
    arr[3]=0;
    arr[4]=0;
    arr[5]=0;
   t.add(3,t.getRoot(),arr,1,i);
   i=0;
    t.add(4,t.getRoot(),arr,2,i);
    i=0;
    t.add(5,t.getRoot(),arr,5,i);
   t.printDown(t.getRoot());

   delete[]arr;
    return 0;
}
