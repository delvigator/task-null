#include <iostream>
using namespace std;
#ifndef TASK0_BOXSTRUCTHEADER_H
#define TASK0_BOXSTRUCTHEADER_H
struct Box
{
    int width;
    int length;
    int height;
    double weight;
    int value;
    Box();
    Box(int width, int length, int height, double weight, int value);

};
int getSumOfValue(Box* array,int size);
bool checkSumOfDataLess(Box* array, int num,int size);
double maxWeightOfBox(Box* array, int maxV, int size);
bool checkOfPut(Box* array,int size);
bool operator==(Box box1, Box box2);
ostream &operator<<(ostream& out,Box &box);
istream& operator>>(istream &in,Box &box);

#endif //TASK0_BOXSTRUCTHEADER_H
