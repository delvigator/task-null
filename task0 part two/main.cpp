
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
   cout<<"\ncount boxes: "<< countB;
   cout<<"\nsum of value: "<< sumV;
   cout<<"\nget box: "<< box;
   cout<<container;
   container.deleteBox(2);
   cout<<"\nadded: "<<container.putBox(boxOne);
    cout<<container;
    cout<<"\noperator []:";
container[2]=boxThree;
    cout<<container;
}
