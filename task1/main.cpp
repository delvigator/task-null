#include <iostream>
#include "DynamicArrayIntegerNumbers.h"
using namespace std;
int main() {
   DynamicArray dynamicArray1(3,3);
    DynamicArray dynamicArray2(3,2);
    DynamicArray dynamicArray3(3,3);
    DynamicArray dynamicArray(dynamicArray1);
    cout<<"\na==b: "<<(dynamicArray1==dynamicArray3);
    cout<<"\na!=b: "<<(dynamicArray1!=dynamicArray2);
    cout<<"\na<b: "<<(dynamicArray2<dynamicArray1);
    cout<<"\na>b: "<<(dynamicArray1>dynamicArray2);
    cout<<"\na>=b(a>b): "<<(dynamicArray1>=dynamicArray2);
    cout<<"\na>=b(a=b): "<<(dynamicArray1>=dynamicArray3);
    cout<<"\na<=b(a<b): "<<(dynamicArray2<=dynamicArray1);
    cout<<"\na<=b(a=b): "<<(dynamicArray1<=dynamicArray3);
    dynamicArray1=dynamicArray2;
    cout<<endl<<dynamicArray1;
   cout<<endl<<dynamicArray;
   dynamicArray1=dynamicArray2+dynamicArray3;
    cout<<endl<<dynamicArray1;
    dynamicArray1.resize(7);
    cout<<endl<<dynamicArray1;
    return 0;
}
