#ifndef TREE_H
#define TREE_H

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class Tree{
private:
    T value;
    int weight;
    vector<Tree<T>*> children;

    void remove_children();
    void copy(const Tree<T>&);

public:
    Tree(const T& = T(), const int& = 0);
    Tree(const Tree<T>&);
    Tree<T>& operator=(const Tree<T>&);
    ~Tree();
    void add_node(const T& = T(), const int& = 0);
//    void remove_tree(const Tree<T>*);
    void remove_nth_child_tree(const size_t& pos);
    void print_tree(int = 0)const;
    void add_tree(const Tree<T>& = Tree<T>());
};

#endif // TREE_H
