#include <iostream>
#include <utility>
#include "Tree.h"
Tree::Tree() {
    root= new TreeElem(0);
  //root= nullptr;
   root->right= nullptr;
   root->left= nullptr;
    //root->check= false;

    count=0;
}
Tree::~Tree() {
    delete root;
    count=0;
}

TreeElem *Tree::getRoot() {
    return root;
}

int Tree::getCount() const {
    return count;
}
TreeElem* Tree::add(int x,TreeElem* root,int *arr,int size,int &i) {
// условие выхода: если дерево пустое, просто вставим элемент в корень
    if (!root) {
        return new TreeElem(x);
    }
// в непустом дереве выполняем поиск
    if (arr[i]==0) {
        root -> left = add(x,root -> left, arr,size,i);
    }
    if (arr[i]==1) {
        root -> right = add(x,root -> right, arr,size,i);
    }
    return root; // возвращаем корень модифицированного дерева
}

Tree &Tree::operator=(Tree o) {
    std::swap(*this,o);
    return *this;

}


void Tree::printDown(const TreeElem*temp)
{

    if (!temp) {
        return;
    }
    std::cout << temp -> info << " ";
    printDown(temp -> left);
    printDown(temp -> right);
}

std::ostream &operator<<(std::ostream &out,Tree &tree) {
    if (!tree.getRoot()) {
        out<<"";
    }
    out<<tree.getRoot()->info<<" ";
out<<tree.getRoot()->left;
out<<tree.getRoot()->right;
}

int Tree::countNumbers(TreeElem *current,int &result) {

    if (!current) {
        return result;
    }
    if(current->info%2==0) result++;
    countNumbers(current -> left,result);
    countNumbers(current -> right,result);
}
