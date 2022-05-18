
#include "Container.h"
#include "Box.h"
namespace cls{
    class Box;
    class Container;
}
int main() {
    Box boxOne = Box(4, 5, 8, 2, 3000);
    Box boxTwo = Box(2, 4, 7, 4, 2000);
    Box boxThree = Box(1, 3, 6, 1, 1000);
   Container container(10,10,10,10);
   container.putBox(boxOne);
   container.putBox(boxTwo);
   container.putBox(boxThree);
   Box box=container.getBox(2);
   int countB=container.countBoxes();
   int sumV=container.getSumOfValue();
    std::cout<<"\ncount boxes: "<< countB;
    std::cout<<"\nsum of value: "<< sumV;
    std::cout<<"\nget box: "<< box;
    std::cout<<container;
   container.deleteBox(2);
    std::cout<<"\nadded: "<<container.putBox(boxOne);
    std::cout<<container;
    std::cout<<"\noperator []:";
container[2]=boxThree;
    std::cout<<container;
}
