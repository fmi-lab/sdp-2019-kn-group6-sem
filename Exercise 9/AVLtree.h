#ifndef __AVLtree_H
#define __AVLtree_H

#include <iostream>

template <class T>
struct AVLnode
{
    T data;
    AVLnode *left, *right;
    int balance;

    AVLnode (const T& = T(), AVLnode* = nullptr, AVLnode* = nullptr, const int& = 0);
    AVLnode ();

    AVLnode<T>* inorderSuccessor();
    AVLnode<T>* inorderSuccessorHelp( AVLnode<T>*);
};

template <class T>
class AVLtree
{

    public:
        AVLtree ();
        AVLtree (const T&);

        void prettyPrint (std::ostream&);

        bool member (const T& x);

        void leftRotate(AVLnode<T>*&);
        void rightRotate(AVLnode<T>*&);

        int insertElement(const T& = T(), AVLnode<T>*&);

        int deleteElement(const T& x, AVLnode<T>*& node);

        int getBalance()const{
            return root->balance;
        }

        AVLnode<T>* getRoot(){
            return root;
        }

    private:
        AVLnode<T> *root;

        void prettyPrintHelp (std::ostream&, AVLnode<T> *current, int level);

        bool memberHelp (const T& x, AVLnode<T> *current);
};


#endif
