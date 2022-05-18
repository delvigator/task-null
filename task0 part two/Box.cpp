#include "Box.h"
Box::Box() {
    width = 0;
    length = 0;
    height = 0;
    weight = 0;
    value = 0;
}
Box::Box(int width, int length, int height, double weight, int value) {
    this->height = height;
    this->length = length;
    this->weight = weight;
    this->value = value;
    this->width = width;

}

void Box::setWidth(int width) {
    this->width = width;
}
void Box::setLength(int length) {
    this->length = length;
}
void Box::setHeight(int height) {
    this->height = height;
}
void Box::setWeight(double weight) {
    this->weight = weight;
}
void Box::setValue(int value) {
    this->value = value;
}
int Box::getWidth() {
    return width;
}
int Box::getLength() {
    return length;
}
int Box::getHeight(){
    return height;
}
double Box::getWeight() {
    return weight;
}
int Box::getValue() {
    return value;

}

bool operator==(Box box1, Box box2) {
    //оператор сравнения двух коробок на равенство
    if (box1.getHeight() == box2.getHeight() && box1.getLength() == box2.getLength()
        && box1.getValue() == box2.getValue() && abs(box1.getWeight() - box2.getWeight()) < 1e-6
        && box1.getWidth() == box2.getWidth())
        return true;
    return false;
}

std::ostream &operator<<(std::ostream& out,Box &box) {
    //оператор вывода
    out << "{width:" << box.getWidth() << ", length:" << box.getLength()
        << ", height:" << box.getHeight() << ", weight:" << box.getWeight()
        << ", value:" << box.getValue() << "}";
}

std::istream& operator>>(std::istream &in,Box &box) {
    //оператор ввода
    int width;
    int length;
    int height;
    double weight;
    int value;
    std::cout << "enter width";
    in >> width;
    box.setWidth(width);
   std:: cout << "enter length";
    in >> length;
    box.setLength(length);
    std::cout << "enter height";
    in >> height;
    box.setHeight(height);
    std::cout << "enter weight";
    in >> weight;
    box.setWeight(weight);
   std:: cout << "enter value";
    in >> value;
    box.setValue(value);
}

