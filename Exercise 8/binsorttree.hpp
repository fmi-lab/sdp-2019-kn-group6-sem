#ifndef __BINTREE_HPP
#define __BINTREE_HPP

#include "binsorttree.h"
#include <cstring>
#include <cassert>
#include <iomanip>

using namespace std;

template <class T>
BinTreeNode<T>::BinTreeNode (const T& _data, BinTreeNode<T>* _left, BinTreeNode<T>* _right):data(_data),left(_left),right(_right) {}

template <class T>
BinTreeNode<T>::BinTreeNode ()
{}


template <class T>
BinTree<T>::BinTree ()
{
    root = nullptr;
}

template <class T>
BinTree<T>::BinTree (const T &x)
{
    root = new BinTreeNode<T> (x,nullptr,nullptr);
}

/*template <class T>
BinTree<T>::BinTree (const T &x, const BinTree<T> &l, const BinTree<T> &r)
{
    root = new BinTreeNode<T> (x,l.root, r.root);
}*/

template <class T>
void BinTree<T>::addHelp(BinTreeNode<T>*& current, const T& x)
{
    if(!current)
    {
        current = new BinTreeNode<T>(x, nullptr, nullptr);
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
void BinTree<T>::addElement(const T& x)
{
    addHelp(root, x);
}


template <class T>
void BinTree<T>::printTree (std::ostream& out)
{
    printTreeHelp (out, root);
}

template <class T>
void BinTree<T>::printTreeHelp (std::ostream& out, BinTreeNode<T> *current)
{
    if (current == nullptr)
    {
        return;
    }

    printTreeHelp (out,current->left);
    out << current->data << " ";
    printTreeHelp (out,current->right);

}

template <class T>
void BinTree<T>::prettyPrint (std::ostream& out)
{
    prettyPrintHelp (out, root, 0);
}

template <class T>
void BinTree<T>::prettyPrintHelp (std::ostream& out, BinTreeNode<T> *current, int level)
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
void BinTree<T>::dottyPrint (std::ostream& out)
{
    out << "digraph G {" << std::endl;
    dottyPrintHelp (out, root);
    out << "}";
}

template <class T>
void BinTree<T>::dottyPrintHelp (std::ostream& out, BinTreeNode<T> *current)
{

    if (current == nullptr)
    {
        return;
    }

    if (current->left != nullptr)
    {
        out << (long)current << "->" << (long)current->left << "[color=\"red\"];" << std::endl;
    }
    if (current->right != nullptr)
    {
        out << (long)current << "->" << (long)current->right << "[color=\"green\"];" << std::endl;
    }


    out << (long)current << "[label=\"" << current->data << "\"];" << std::endl;

    dottyPrintHelp (out, current->right);
    dottyPrintHelp (out, current->left);

}

template <class T>
bool BinTree<T>::member (const T& x)
{
    return memberHelp (x,root);
}

template <class T>
bool BinTree<T>::memberHelp (const T& x, BinTreeNode<T> *current)
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
T BinTree<T>::sum ()
{
    return sumHelp (root);
}

template <class T>
T BinTree<T>::sumHelp (BinTreeNode<T> *current)
{
    if (current == nullptr)
    {
        return 0;
    }

    return current->data +
           sumHelp (current->left) +
           sumHelp (current->right);
}

template <class T>
T BinTree<T>::reduce (T (*op)(const T&, const T&), const T& null_val)
{
    return reduceHelp (op,null_val, root);
}

template <class T>
T BinTree<T>::reduceHelp (T (*op)(const T&, const T&), const T& null_val, BinTreeNode<T> *current)
{
    if (current == nullptr)
    {
        return null_val;
    }

    return op (current->data,
               op (reduceHelp (op,null_val,current->left),
                   reduceHelp (op,null_val,current->right)));
}

template <class T>
void BinTree<T>::mapHelp (T (*op)(const T&), BinTreeNode<T>* current)
{
    op(current->data);
    mapHelp(op, current->left);
    mapHelp(op, current->right);
}

template <class T>
void BinTree<T>::mapTree (T (*op)(const T&))
{
    mapHelp(op, root);
}

template <class T>
BinTree<T> BinTree<T>::mirrorHelp(BinTree<T>& result, const BinTreeNode<T>* current, const char* position)const
{
    cout<<position<<endl;
    result.addElement(position, current->data);
    char* newR = new char(strlen(position) + 1);
    assert(newR);
    strcpy(newR, position);
    strcpy(newR, strcat(newR, "R"));
    char* newL = new char(strlen(position) + 1);
    assert(newL);
    strcpy(newL, position);
    strcpy(newL, strcat(newL, "L"));
    if(current->left)
    {
        mirrorHelp(result, current->left, newR);
    }
    if(current->right)
    {
        mirrorHelp(result, current->right, newL);
    }
    return result;
}

template <class T>
BinTree<T> BinTree<T>::mirrorTree()const
{
    BinTree<T> tree;
    return mirrorHelp(tree, root, "");
}

#endif
