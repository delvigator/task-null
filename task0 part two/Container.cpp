
#include "Container.h"
#include "WeightExeption.cpp"

Container::Container(int length, int width, int height, double maxWeight) {
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight=maxWeight;

}
int Container::countBoxes(){
    int count=0;
    for(int i=0;i<containerOfBoxes.size();i++){
        count++;
    }
    return count;
}
int Container::getLength(){
    return length;
}
int Container::getWidth(){
    return width;
}
int Container::getHeight(){
    return height;
}
double Container::getMaxWeight(){
    return maxWeight;
}

void Container::setLength(int length) {
    Container::length = length;
}

void Container::setWidth(int width) {
    Container::width = width;
}

void Container::setHeight(int height) {
    Container::height = height;
}

void Container::setMaxWeight(double maxWeight) {
    if(getSumOfWeight()>maxWeight) throw WeightException("new max weight lesser than sum of weight");
    Container::maxWeight = maxWeight;
}

double Container::getSumOfWeight(){
    double sum=0;
    for(int i=0;i<containerOfBoxes.size();i++){
        sum+=containerOfBoxes[i].getWeight();
    }
    return sum;
}
int Container::getSumOfValue(){
int sum=0;
    for(int i=0;i<containerOfBoxes.size();i++){
        sum+=containerOfBoxes[i].getValue();
    }
    return sum;
}
Box Container::getBox(int index){
return containerOfBoxes[index];
}
int Container::putBox(Box box){
    double check=getSumOfWeight()+box.getWeight();
    if(check>maxWeight) throw WeightException("max weight has been exceeded");
    containerOfBoxes.push_back(box);
    return containerOfBoxes.size()-1;
}
int Container::deleteBox(int index){
containerOfBoxes.erase(containerOfBoxes.begin()+index);
return 0;
}
Box &Container::operator[](int index){
    return containerOfBoxes[index];
}
ostream &operator<<(ostream& out,Container& container){
    out<<"\n{length: "<<container.getLength()<<", width: "<<container.getWidth()
    <<", height: "<<container.getHeight()<<", maxWeight: "<<container.getMaxWeight()<<"\nBoxes: \n";
    for (int i=0;i<container.countBoxes();i++){
       out<< container[i]<<"\n";
    }
    cout<<"}\n";
}
istream& operator>>(istream &in,Container &container) {
    int length;
    int width;
    int height;
    double maxWeight;
    cout << "enter width";
    in >> width;
    container.setWidth(width);
    cout << "enter length";
    in >> length;
    container.setLength(length);
    cout << "enter height";
    in >> height;
    container.setHeight(height);
    cout << "enter max weight";
    in >> maxWeight;
    container.setMaxWeight(maxWeight);
}