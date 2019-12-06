#ifndef __AVLtree_HPP
#define __AVLtree_HPP

#include "AVLtree.h"
#include <cstring>
#include <cassert>
#include <iomanip>

using namespace std;

template <class T>
AVLnode<T>::AVLnode (const T& _data, AVLnode<T>* _left, AVLnode<T>* _right, const int& balance):data(_data),left(_left),right(_right), balance(balance) {}

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

template <class T>
void AVLtree<T>::leftRotate(AVLnode<T>*& node){
    if(!node->right){
        return;
    }

    AVLnode<T>* temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;

    temp->balance = temp->balance - 1;
    if(node->balance > 0){
        temp->balance = temp->balance - node->balance;
    }
    node->balance = node->balance - 1;
    if(temp->balance < 0){
        node->balance = node->balance + temp->balance;
    }
}

template <class T>
void AVLtree<T>::rightRotate(AVLnode<T>*& node){
    if(!node->left){
        return;
    }

    AVLnode<T>* temp = node;
    node = node->left;
    temp->left = node->right;
    node->right = temp;

    temp->balance = temp->balance + 1;
    if(node->balance < 0){
        temp->balance = temp->balance - node->balance;
    }
    node->balance = node->balance + 1;
    if(temp->balance > 0){
        node->balance = node->balance + temp->balance;
    }
}

template <class T>
int AVLtree<T>::insertElement(const T& x, AVLnode<T>*& node){
    int h = 0;
    if(!node){
        node = new AVLnode<T>(x, nullptr, nullptr, 0);
        assert(node);
        h = 1;
    }
    else if(x > node->data){
        ///включваме го в ДПД
        if(insertElement(x, node->right)){
            node->balance++;
            if(node->balance == 1){
                h = 1;
            } else if(node->balance == 2){
                if(node->right->balance == -1){
                    rightRotate(node->right);
                }
                leftRotate(node);
            }
        }
    } else if(x <= node->data){
        ///включваме го в ЛПД
        if(insertElement(x, node->left)){
            node->balance--;
            if(node->balance == -1){
                h = -1;
            } else if(node->balance == -2){
                if(node->left->balance == 1){
                    leftRotate(node->left);
                }
                rightRotate(node);
            }
        }
    }
    return h;
}

int AVLtree<T>::deleteElement(const T& x, AVLnode<T>*& node){
    int h = 0;
    AVLnode<T>* temp;
    if(!node){
        return 0;
    }
    if(x < node->data){
        if(deleteElement(x, node->left)){
            node->balance++;
            if(node->balance == 0){
                h = 1;
            } else if(node->balance == 2){
                if(node->right->balance == -1){
                    rightRotate(node->right);
                }
                leftrRotate(node);
                if (node->balance == 0) h = 1;
            }
        }
    } else if (x > node->data){
        if(deleteElement(x, node->right)){
            node->balance --;
            if(node->balance == 0){
                h = 1;
            } else if (node->balance == -2){
                if(node->left->balance == 1){
                    leftRotate(node->left);
                }
                rightRotate(node);
                if (node->balance == 0) h = 1;
            }
        }
    } else {
        if(!node->right){
            temp = node;
            node = node->left;
            delete temp;
            return 1;
        } else if(!node->left){
            temp = node;
            node = node->right;
            delete temp;
            return 1;
        } else{
            int t = node->data;
            AVLnode<T>* succ = inorderSuccessor();
            node->data = succ->data;
            succ->data = t;
            deleteElement(t, node->left);
        }
    }
}

#endif
