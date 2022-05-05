#include <iostream>
#include "BoxStructHeader.h"

using namespace std;

Box::Box() {
    this->height = 0;
    this->length = 0;
    this->weight = 0;
    this->value = 0;
    this->width = 0;
}

Box::Box(int width, int length, int height, double weight, int value) {
    this->height = height;
    this->length = length;
    this->weight = weight;
    this->value = value;
    this->width = width;
}

int getSumOfValue(Box *array, int size) {
    //2. вычисляет суммарную стоимость содержимого всех коробок.

    int sumOfValue = 0;
    for (int i = 0; i < size; i++) {
        sumOfValue += array[i].value;
    }
    return sumOfValue;
}

bool checkSumOfDataLess(Box *array, int num, int size) {
    //3. проверяет, что сумма длины, ширины и высоты всех коробок
    // не превосходит заданного значения.
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i].height + array[i].length + array[i].width;

    }
    if (sum > num) return false;
    else return true;
}

double maxWeightOfBox(Box *array, int maxV, int size) {
    //4. определяет максимальный вес коробок, объем которых не
    // больше параметра maxV
    double maxWeightOfBox = 0;
    int volumeOfBox = 0;
    for (int i = 0; i < size; i++) {
        volumeOfBox = array[i].width * array[i].height * array[i].length;
        if (volumeOfBox < maxV || volumeOfBox == maxV) {
            if (array[i].weight > maxWeightOfBox) {
                maxWeightOfBox = array[i].weight;
            }
        }
    }
    return maxWeightOfBox;

}

bool checkOfPut(Box *array, int size) {
    //5. проверка, можно ли запихать коробки в коробки
    int count = 0;
    int maxVolumeNow = -1;
    int volume;
    int line = -1;
    bool fail = false;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            volume = array[i].width * array[i].height * array[i].length;
            if (volume > maxVolumeNow) {
                if (line == -1 | volume < line)
                    maxVolumeNow = volume;
            }

        }
        if (maxVolumeNow == -1) fail = true;

        if (line == -1 | maxVolumeNow < line) {
            line = maxVolumeNow;
            count++;
        }
        maxVolumeNow = -1;

    }
    if (count == size && !fail) return true;
    return false;

}

bool operator==(Box box1, Box box2) {
    //оператор сравнения двух коробок на равенство
    if (box1.height == box2.height && box1.length == box2.length
        && box1.value == box2.value && abs(box1.weight - box2.weight) < 1e-6
        && box1.width == box2.width)
        return true;
    return false;
}

ostream &operator<<(ostream& out,Box &box) {
    //оператор вывода
    out << "{width:" << box.width << ", length:" << box.length
         << ", height:" << box.height << ", weight:" << box.weight
         << ", value:" << box.value << "}";
}

istream& operator>>(istream &in,Box &box) {
    //оператор ввода
    cout << "enter width";
    in >> box.width;
    cout << "enter length";
    in >> box.length;
    cout << "enter height";
    in >> box.height;
    cout << "enter weight";
    in >> box.weight;
    cout << "enter value";
    in >> box.value;
}


