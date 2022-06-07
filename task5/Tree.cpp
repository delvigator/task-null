#include <iostream>
#include <utility>
#include "Tree.h"
Tree::Tree() {
    root= new TreeElem();
   root->right= nullptr;
   root->left= nullptr;

}
Tree::Tree(int x) {
    root= new TreeElem();
    root->info=x;
    root->right= nullptr;
    root->left= nullptr;

}
void Tree::clear(TreeElem* root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}
void Tree::clear() {
    if (root != nullptr) {
        clear(root);
        root = nullptr;
    }
}


Tree::~Tree() {
    clear();

}
Tree::Tree(const Tree& o) {
    std::cout << "Конструктор копирования" << std::endl;
    root = copyTree(o.root);
}

TreeElem * Tree::copyTree(TreeElem *o) {
    if (o != nullptr) {
        return new TreeElem(o->info,copyTree(o->left), copyTree(o->right));
    }
    return nullptr;
}
Tree::Tree(Tree&& o) noexcept : root(o.root) {
    o.root = nullptr;
}


TreeElem *Tree::getRoot() {
    return root;
}
Tree& Tree::operator=(const Tree& obj) {
    if (this != &obj) {
        delete root;
        root = copyTree(obj.root);
    }
    return *this;
}

Tree& Tree::operator=(Tree&& obj) noexcept {
    if (this != &obj) {
        delete root;
        root = obj.root;
        obj.root = nullptr;
    }
    return (*this);
}


int Tree::add(int x,const std::vector<bool>& arr) {
    if (!root) {
        if (!arr.empty()) {
            throw std::exception();
        }
        root = new TreeElem;
        root->info = x;

    }
    else {
    TreeElem* current = root;
    unsigned size = arr.size();
    for (unsigned i = 0; i < size; i++) {
    if (i == size - 1) {
    TreeElem* old = current;
    current = new TreeElem;
    arr[i] ? old->right = current : old->left = current;
    current->left = nullptr;
    current->right = nullptr;
}
    else if (arr[i] && current->right != nullptr) {
    current = current->right;
}
    else if (!arr[i] && current->left != nullptr) {
    current = current->left;
}
    else {
throw std::exception();
}
}
current->info = x;
}
return 0;

}
std::ostream& operator<<(std::ostream& out, Tree& obj) {
    obj.print(obj.root,out);
    return out;
}
void Tree:: print(TreeElem* root,std::ostream& out)
{
    if (!root) {
        return;

    }
    out << root -> info << " ";
    print(root -> left,out);
    print(root -> right,out);
}
/*void Tree::Print(std::ostream& out) {
    Print(root, out);
}

void Tree::Print(TreeElem* elem, std::ostream& out) {
    if (elem != nullptr) {
        out << elem->info << "\n";
        Print(elem->left, out);
        Print(elem->right, out);
    }
}
*/
unsigned Tree::countOfEven() {
    return countOfEven(root);
}

unsigned Tree::countOfEven(TreeElem* elem) {
    return (elem == nullptr ? 0 :
            (elem->info % 2 == 0) + countOfEven(elem->left) + countOfEven(elem->right));
}

bool Tree::allPositive() {
    return allPositive(root);
}

bool Tree::allPositive(const TreeElem* elem) {
    return elem == nullptr || elem->info > 0 && allPositive(elem->left) && allPositive(elem->right);
}

void Tree::deleteLeaves() {
    deleteLeaves(root);
}
bool Tree::deleteLeaves(TreeElem* elem) {
    if (elem == nullptr) {
        return false;
    }
    else {
        if (elem->right == nullptr && elem->left == nullptr) {
            delete elem;
            return true;
        }
        if (deleteLeaves(elem->left)) {
            elem->left = nullptr;
        }
        if (deleteLeaves(elem->right)) {
            elem->right = nullptr;
        }
        return false;
    }
}
double Tree::average() {
    std::pair<long, int> res(0, 0);
    average(root, res);
    return ((double)res.first) / res.second;
}

void Tree::average(const TreeElem* elem, std::pair<long, int>& values) {
    if (elem != nullptr) {
        values.first += elem->info;
        values.second += 1;
        average(elem->left, values);
        average(elem->right, values);
    }
}

std::vector<bool> Tree::searchElem(int x) {
    std::vector<bool> res{};
    if (!searchElem(root, res, x)) {
        throw std::exception();
    }
    return res;
}

bool Tree::searchElem(TreeElem* const elem, std::vector<bool>& arr, int x) {
    if (elem != nullptr) {
        if (elem->info == x) {
            return true;
        }
        arr.push_back(false);
        if (searchElem(elem->left, arr, x)) {
            return true;
        }
        arr.pop_back();
        arr.push_back(true);
        if (searchElem(elem->right, arr, x)) {
            return true;
        }
        arr.pop_back();
    }
    return false;
}
