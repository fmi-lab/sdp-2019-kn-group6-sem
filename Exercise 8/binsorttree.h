#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
struct BinTreeNode
{
    T data;
    BinTreeNode *left, *right;

    BinTreeNode (const T&, BinTreeNode*, BinTreeNode*);
    BinTreeNode ();
};

template <class T>
class BinTree
{

    public:
        BinTree ();
        BinTree (const T&);
//        BinTree (const T&, const BinTree<T>&, const BinTree<T>&);

        void addElement (const T&);

        void printTree (std::ostream&);
        void prettyPrint (std::ostream&);
        void dottyPrint (std::ostream&);

        bool member (const T& x);
        T sum ();
        BinTree<T> mirrorTree()const;

        T reduce (T (*op)(const T&, const T&), const T& null_val);
        void mapTree (T (*op)(const T&));

    private:
        BinTreeNode<T> *root;

        void addHelp(BinTreeNode<T>*&, const T&);

        void printTreeHelp (std::ostream&, BinTreeNode<T> *current);
        void prettyPrintHelp (std::ostream&, BinTreeNode<T> *current, int level);
        void dottyPrintHelp (std::ostream&, BinTreeNode<T> *current);

        bool memberHelp (const T& x, BinTreeNode<T> *current);
        T sumHelp (BinTreeNode<T> *current);

        T reduceHelp (T (*op)(const T&, const T&), const T& null_val, BinTreeNode<T> *current);
        void mapHelp (T (*op)(const T&), BinTreeNode<T>* current);
        BinTree<T> mirrorHelp(BinTree<T>& , const BinTreeNode<T>*, const char*)const;
};


#endif
