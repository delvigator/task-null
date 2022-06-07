#include <iostream>
#include "Tree.h"
int main() {
    std::vector<bool> arr1{};
    Tree tree1;
    arr1.push_back(false);
    tree1.add(3, arr1);
    arr1.push_back(false);
    tree1.add(11, arr1);
    arr1.push_back(false);
    tree1.add(7, arr1);
    arr1.pop_back();
    arr1.push_back(true);
    tree1.add(8, arr1);

    std::cout <<"\ntree1\n"<< tree1;
    tree1.deleteLeaves();
    std::cout <<"\ntree1\n"<< tree1;


    Tree tree2(tree1);
    std::cout <<"\ntree2\n"<< tree2;
   std::cout<<std::endl;
    std::cout <<"\ntree1.clear()\n";
   tree1.clear();
    std::cout <<"\ntree2\n";
   std::cout<<tree2<<std::endl;

   std:: vector<bool> arr2{};
    Tree tree3(22);
    arr2.push_back(true);
    tree3.add(4, arr2);
    arr2.pop_back();
    arr2.push_back(false);
    tree3.add(18, arr2);
    arr2.push_back(false);
    tree3.add(5, arr2);

    std::cout << tree3.countOfEven() << std::endl;//должно быть 3
    std::cout << tree3.average() << std::endl; // должно быть 12.25
    std::cout << tree3.allPositive() << std::endl; //true
    tree2.add(-10, arr2);

   std:: cout << tree2.allPositive() << std::endl; //false;
   std:: vector<bool> arr3;
    Tree tree4;

    tree4.add(8, arr3);
    arr3.push_back(false);
    tree4.add(3, arr3);
    arr3.push_back(false);
    tree4.add(-1, arr3);
    arr3.pop_back();
    arr3.push_back(true);
    tree4.add(6, arr3);
    arr3.push_back(true);
    tree4.add(8, arr3);
    arr3.clear();
    arr3.push_back(true);
    tree4.add(10, arr3);
    arr3.push_back(true);
    tree4.add(12, arr3);
    arr3.push_back(false);
    tree4.add(7, arr3);
    Tree tree5 = tree4;


    tree5.deleteLeaves();
    tree5.add(14, arr3);


    std::vector<bool> arr4{};
    Tree tree6;

    tree6.add(8, arr4);
    arr4.push_back(false);
    tree6.add(3, arr4);
    arr4.push_back(false);
    tree6.add(-1, arr4);
    arr4.pop_back();
    arr4.push_back(true);
    tree6.add(6, arr4);
    arr4.push_back(true);
    tree6.add(8, arr4);

    std::cout << tree6 << std::endl;

    arr4.clear();
    arr4.push_back(true);
    tree6.add(10, arr4);
    arr4.push_back(true);
    tree6.add(12, arr4);
    arr4.push_back(false);
    tree6.add(7, arr4);

    std::cout << tree6 << std::endl;

    arr4.clear();
    arr4.push_back(true);
    arr4.push_back(true);
    arr4.push_back(false);

    std::vector<bool> arrB = tree6.searchElem(7);
    if (arr4 == arrB) {
        std::cout << true;
    }

    return 0;
}
