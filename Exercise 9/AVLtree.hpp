#ifndef __AVLtree_HPP
#define __AVLtree_HPP

#include "AVLtree.h"
#include <cstring>
#include <cassert>
#include <iomanip>

using namespace std;

template <class T>
AVLnode<T>::AVLnode (const T& _data, AVLnode<T>* _left, AVLnode<T>* _right):data(_data),left(_left),right(_right) {}

template <class T>
AVLnode<T>::AVLnode ()
{}


template <class T>
AVLtree<T>::AVLtree ()
{
    root = nullptr;
}

template <class T>
AVLtree<T>::AVLtree (const T &x)
{
    root = new AVLnode<T> (x,nullptr,nullptr);
}

template <class T>
void AVLtree<T>::addHelp(AVLnode<T>*& current, const T& x)
{
    if(!current)
    {
        current = new AVLnode<T>(x, nullptr, nullptr);
    }
    else if(current->data < x)
    {
        addHelp(current->right, x);
    }
    else if(current->data >= x)
    {
        addHelp(current->left, x);
    }
}

template <class T>
void AVLtree<T>::addElement(const T& x)
{
    addHelp(root, x);
}

template <class T>
AVLnode<T>* AVLnode<T>::inorderSuccessorHelp( AVLnode<T>* current){
    if(current->right){
        return inorderSuccessorHelp(current->right);
    }
    return current;
}
template <class T>
AVLnode<T>* AVLnode<T>::inorderSuccessor(){
    if(this->left){
        return inorderSuccessorHelp(this);
    }
    return nullptr;
}

template <class T>
void AVLtree<T>::removeHelp(AVLnode<T>* current, const T& x)
{
    AVLnode<T>* cur = current;
    cout<<"current->data = "<<current->data<<endl;
    if(current->left)
    {
        cout<<"go left\n";
        AVLnode<T>* temp = current;
        current = current->left;
        if(current->data == x)
        {
            cout<<"found! "<<x<<endl;
            if(!current->left && !current->right)
            {
                delete current;
                temp->left = nullptr;
            } else if(current->left && !current->right){
                temp->left = current->left;
                delete current;
            } else if(!current->left && current->right){
                temp->left = current->right;
                delete current;
            } else {
                temp = current->inorderSuccessor();
                swap(temp->data, current->data);
                delete temp;
            }
        }
        else
        {
            cout<<"not found() "<<x<<endl;
            removeHelp(current, x);
        }
    }
    current = cur;
    if(current->right)
    {
        cout<<"go right\n";
        AVLnode<T>* temp = current;
        current = current->right;
        if(current->data == x)
        {
            if(!current->left && !current->right)
            {
                delete current;
                temp->right = nullptr;
            } else if(current->left && !current->right){
                temp->right = current->left;
                delete current;
            } else if(!current->left && current->right){
                temp->right = current->right;
                delete current;
            } else {
                temp = current->inorderSuccessor();
                swap(temp->data, current->data);
                delete temp;
            }
        }
        else
        {
            removeHelp(current, x);
        }
    }
}

template <class T>
void AVLtree<T>::removeElement(const T& x)
{
    removeHelp(root, x);
}

template <class T>
void AVLtree<T>::prettyPrint (std::ostream& out)
{
    prettyPrintHelp (out, root, 0);
}

template <class T>
void AVLtree<T>::prettyPrintHelp (std::ostream& out, AVLnode<T> *current, int level)
{
    if (current == nullptr)
    {
        return;
    }

    prettyPrintHelp (out, current->right,level+1);
    out <<setw(level*2) << " " << current->data << std::endl;
    prettyPrintHelp (out, current->left, level+1);

}

template <class T>
bool AVLtree<T>::member (const T& x)
{
    return memberHelp (x,root);
}

template <class T>
bool AVLtree<T>::memberHelp (const T& x, AVLnode<T> *current)
{
    if (current == nullptr)
    {
        return false;
    }

    return current->data == x ||
           memberHelp (x,current->left) ||
           memberHelp (x,current->right);
}


#endif
