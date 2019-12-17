#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;

template <typename T>
struct node
{
    T data;
    node<T>* left;
    node<T>* right;
    node<T>* parrent;

    node(const T& data = T(), node<T>* parrent = nullptr, node<T>* left = nullptr, node<T>* right = nullptr) : data(data), left(left), right(right) {}



};

template <typename T>
void print_tree_helper(const node<T>* curr, unsigned depth)
{
    if(!curr){
        return;
    }

    print_tree_helper(curr->left, depth + 1);
    for(int i = 0; i<=depth; i++)
    {
        cout<<'\t';
    }
    cout<<curr->data<<endl;
    print_tree_helper(curr->right, depth + 1);
}
template <typename T>
void print_tree(const node<T>* curr)
{
    print_tree_helper(curr, 0);
}

#endif // NODE_H
