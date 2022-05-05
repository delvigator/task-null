
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
    return 0;
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