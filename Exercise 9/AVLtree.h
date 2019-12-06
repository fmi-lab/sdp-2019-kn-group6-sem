#ifndef __AVLtree_H
#define __AVLtree_H

#include <iostream>

template <class T>
struct AVLnode
{
    T data;
    AVLnode *left, *right;

    AVLnode (const T&, AVLnode*, AVLnode*);
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

        void addElement (const T&);
        void removeElement (const T&);

        void prettyPrint (std::ostream&);

        bool member (const T& x);

    private:
        AVLnode<T> *root;

        void addHelp(AVLnode<T>*&, const T&);
        void removeHelp(AVLnode<T>*, const T&);

        void printTreeHelp (std::ostream&, AVLnode<T> *current);
        void prettyPrintHelp (std::ostream&, AVLnode<T> *current, int level);
        void dottyPrintHelp (std::ostream&, AVLnode<T> *current);

        bool memberHelp (const T& x, AVLnode<T> *current);
};


#endif
