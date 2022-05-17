#include "DynamicArrayIntegerNumbers.h"

DynamicArray::DynamicArray() {
    this->size=0;
    array=new int[size];
}
DynamicArray::DynamicArray(int size) {
    this->size=size;
    array=new int[size];
    for(int i=0;i<size;i++)
        array[i]=0;
}
DynamicArray::DynamicArray(int size, int n) {
    this->size=size;
    this->array=new int[size];
    for(int i=0;i<this->size;i++)
       this-> array[i]=n;
}
DynamicArray::DynamicArray(const DynamicArray &n) {
    this->size=n.size;
    this->array=new int[size];
    memcpy(array,n.array,n.size*sizeof(int));

}
DynamicArray::DynamicArray(DynamicArray &&n) {
    this->size=n.size;
    this->array=n.array;
    n.array= nullptr;
    n.size=0;
}
DynamicArray::~DynamicArray() {
    delete [] array;
    size=0;
}

int DynamicArray::getSize() {
    return size;
}

int & DynamicArray::operator[](int index) {
    return array[index];
}

int DynamicArray::resize(int newSize) {
    int sizeCopy=size;
    int *arrayCopy=new int[sizeCopy];
    memcpy(arrayCopy,array,size*sizeof(int));

    this->size=newSize;
    delete []array;
    array=new int[newSize];
    for(int i=0;i<sizeCopy;i++){
            array[i] = arrayCopy[i];
    }
    for(int i=sizeCopy;i<newSize;i++){
        array[i]=0;
    }
    delete[]arrayCopy;
    return 0;
}

bool DynamicArray::operator==(const DynamicArray& arrayN) {
    if(size!=arrayN.size) throw SizeException("wrong size");
    bool check=false;
    for(int i=0;i<size;i++){
        if(array[i]!=arrayN.array[i]) check=true;
    }
    if (check) return false;
    return true;
}
bool DynamicArray::operator!=(const DynamicArray& arrayN) {
    if(size!=arrayN.size) throw SizeException("wrong size");
    bool check=false;
    for(int i=0;i<size;i++){
        if(array[i]==arrayN.array[i]) check=true;
    }
    if (check) return false;
    return true;
}

bool DynamicArray::operator<(const DynamicArray &arrayN)  {
    int biggerSize=max(size,arrayN.size);
    bool check=false;
    bool noEquals=false;
    for(int i=0;i<biggerSize;i++){
        if(!array[i] | !arrayN.array[i]) i=biggerSize;
        if(array[i]>arrayN.array[i]) check=true;
        if(array[i]!=arrayN.array[i]) noEquals= true;
    }
    if(check | !noEquals&(size==arrayN.size) | !noEquals&(size>arrayN.size)) return false;
    return true;
}

bool DynamicArray::operator>(const DynamicArray &arrayN) {
    int biggerSize=max(size,arrayN.size);
    bool check=false;
    bool noEquals=false;
    for(int i=0;i<biggerSize;i++){
        if(!array[i] | !arrayN.array[i]) i=biggerSize;
        if(array[i]<arrayN.array[i]) check=true;
        if(array[i]!=arrayN.array[i]) noEquals= true;
    }
    if(check | !noEquals&(size==arrayN.size) | !noEquals&(size<arrayN.size)) return false;
    return true;
}

bool DynamicArray::operator<=(const DynamicArray &arrayN) {
    int biggerSize=max(size,arrayN.size);
    bool check=false;
    bool noEquals=false;
    for(int i=0;i<biggerSize;i++){
        if(!array[i] | !arrayN.array[i]) i=biggerSize;
        if(array[i]>arrayN.array[i]) check=true;
        if(array[i]!=arrayN.array[i]) noEquals= true;
    }
    if(check  | !noEquals&(size>arrayN.size)) return false;
    return true;
}

bool DynamicArray::operator>=(const DynamicArray &arrayN) {
    int biggerSize=max(size,arrayN.size);
    bool check=false;
    bool noEquals=false;
    for(int i=0;i<biggerSize;i++){
        if(!array[i] | !arrayN.array[i]) i=biggerSize;
        if(array[i]<arrayN.array[i]) check=true;
        if(array[i]!=arrayN.array[i]) noEquals= true;
    }
    if(check | !noEquals&(size<arrayN.size)) return false;
    return true;
}

DynamicArray DynamicArray::operator+( DynamicArray &array1) {
    int newSize=size+array1.size;
    DynamicArray result(newSize);
for(int i=0;i<size;i++){
    result[i]=array[i];
}
int j=0;
    for(int i=array1.getSize();i<newSize;i++){
        result[i]=array1.array[j];
        j++;
    }
    return result;
}

 ostream &operator<<(ostream &out,DynamicArray &dynamicArray) {
     out<<"{size: "<<dynamicArray.getSize()<<", array: {";
    for(int i=0;i<dynamicArray.getSize();i++){
        out<<dynamicArray[i]<<" ";
    }
    out<<"}}";

}

istream &operator>>(istream &in,DynamicArray &dynamicArray) {
    cout<<"enter integer numbers";
    int number;
    for(int i=0;i<dynamicArray.getSize();i++){
        cout<<"["<<i<<"]\n";
        in>>number;
        dynamicArray[i]=number;
    }
}


DynamicArray &DynamicArray::operator=(const DynamicArray &arrayN) {

     if(this==&arrayN) return *this;
     int* arrayCopy=new int[arrayN.size];
     if(array)  delete[]array;
        size = arrayN.size;
        array = arrayCopy;
    memcpy(array,arrayN.array,arrayN.size*sizeof(int));

return *this;
}
DynamicArray &DynamicArray::operator=(DynamicArray &&arrayN) noexcept {
    if(this!=&arrayN){
        delete[]array;
        size=arrayN.size;
        array=arrayN.array;

        arrayN.array= nullptr;
        arrayN.size=0;
    }
    return *this;

}
