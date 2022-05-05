#include <iostream>
#include "Container.h"
#include "Box.h"
namespace cls{
    class Box;
    class Container;
}
int main() {
    Box boxOne = Box(4, 5, 8, 5, 3000);
    Box boxTwo = Box(2, 4, 7, 4, 2000);
    Box boxThree = Box(1, 3, 6, 1, 1000);
   Container container(10,10,10,10);
   container.putBox(boxOne);
   container.putBox(boxTwo);
   container.putBox(boxThree);
   int count=container.countBoxes();
   cout<<"count boxes: "<< count;
   cout<<container;
}
