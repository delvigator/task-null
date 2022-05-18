
#include <iostream>

#ifndef TASK0_BOX_H
#define TASK0_BOX_H
class Box {
private:
    int width;
    int length;
    int height;
    double weight;
    int value;

public:
    Box();
    Box(int width, int length, int height, double weight, int value);
    void setWidth(int width);
    void setLength(int length);
    void setHeight(int height);
    void setWeight(double weight);
    void setValue(int value);
    int getWidth();
    int getLength();
    int getHeight();
    double getWeight();
    int getValue();


};

bool operator==(Box box1, Box box2);
std::ostream &operator<<(std::ostream& out,Box &box);
std::istream& operator>>(std::istream &in,Box &box);

#endif //TASK0_BOX_H
