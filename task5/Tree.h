//
// Created by эльф on 07.06.2022.
//

#ifndef TASK5_TREE_H
#define TASK5_TREE_H

struct TreeElem {
    int info;
    TreeElem* left;
    TreeElem* right;
    bool check;
  TreeElem(int theInfo,
        TreeElem* theLeft = nullptr,
         TreeElem* theRight = nullptr): info(theInfo), left(theLeft), right(theRight) {}
};
class Tree {
TreeElem* root;
int count;
public:
Tree();
~Tree();
int getCount() const;
TreeElem *getRoot();
TreeElem*add(int x,TreeElem*current,int*arr,int size,int &i);
void printDown(const TreeElem*current);
    Tree &operator=(Tree o);
    int countNumbers(TreeElem*current,int &result);
};


#endif //TASK5_TREE_H
