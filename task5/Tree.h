#include <vector>
#include <iostream>
#ifndef TASK5_TREE_H
#define TASK5_TREE_H

struct TreeElem {
    int info;
    TreeElem* left;
    TreeElem* right;
    explicit TreeElem(int info,TreeElem *left,TreeElem *right): info(info), left(left), right(right) {}
  explicit TreeElem(): info(0), left(nullptr), right(nullptr) {}

};
class Tree {
TreeElem* root;
    void clear(TreeElem *root);
    TreeElem * copyTree(TreeElem* o);
    unsigned countOfEven(TreeElem* elem);
public:
Tree();
Tree(int x);
Tree(const Tree& o);
Tree(Tree&& o) noexcept;
~Tree();


void clear();


TreeElem *getRoot();
int add(int x,const std::vector<bool>& arr);
    //void Print(TreeElem* elem, std::ostream& out);
   // void Print(std::ostream& out);
    void print(TreeElem* elem,std::ostream& out);
    unsigned countOfEven();

    bool allPositive();
    bool allPositive(const TreeElem* elem);
    void deleteLeaves();
    bool deleteLeaves(TreeElem* elem);
    Tree& operator=(const Tree& obj);
    Tree& operator=(Tree&& obj) noexcept;
    double average();
    void average(const TreeElem* elem, std::pair<long, int>& values);
    std::vector<bool> searchElem(int x);
    bool searchElem(TreeElem* elem, std::vector<bool>& arr, int x);
   friend std::ostream& operator<<(std::ostream& out, Tree& obj);
};


#endif //TASK5_TREE_H
