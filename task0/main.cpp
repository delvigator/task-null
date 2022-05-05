#include <iostream>
#include "BoxStructHeader.h"

using namespace std;

int main() {
    int size = 3;
    Box *array = new Box[size];
    Box boxOne = Box(4, 5, 8, 5, 3000);
    Box boxTwo = Box(2, 4, 7, 4, 2000);
    Box boxThree = Box(1, 3, 6, 3, 1000);
    Box box =Box(4, 5, 8, 5, 3000);

    array[2] = boxOne;
    array[1] = boxTwo;
    array[0] = boxThree;

    int sum = getSumOfValue(array, size);
    bool check = checkSumOfDataLess(array, 50, size);
    double maxWeight = maxWeightOfBox(array, 60, size);
    bool num = checkOfPut(array, size);
    bool eq= boxOne==box;
    cout << "sum of prices: " << sum;
    cout << "\nsum of height,length,width all boxes less than number: " << check;
    cout << "\nmax weight of boxes whose V less than maxV: " << maxWeight;
    cout << "\ncheck of put " << num;
    cout<<"\nequals: "<<eq<<"\n";
    cin>>boxOne;
    cout<<boxOne;
    delete[] array;
}