
#include <vector>
#include "Box.h"
#include <iostream>

#ifndef TASK0_CONTAINER_H
#define TASK0_CONTAINER_H

class Container {
private:
    std::vector<Box> containerOfBoxes;
    int length;
    int width;
    int height;
    double maxWeight;
public:
    Container(int length, int width,int height, double maxWeight);
    int getLength();
    int getWidth();
    int getHeight();
    double getMaxWeight();
    int countBoxes();
    double getSumOfWeight();
    int getSumOfValue();
    Box getBox(int index);
    int putBox(Box box);
    int deleteBox(int index);
    Box &operator[](int index);

    void setLength(int length);

    void setWidth(int width);

    void setHeight(int height);

    void setMaxWeight(double maxWeight);

};
std::ostream &operator<<(std::ostream& out,Container& container);

#endif //TASK0_CONTAINER_H
