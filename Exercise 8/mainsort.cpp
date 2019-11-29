#include "binsorttree.h"
#include "binsorttree.hpp"

int main(){
    BinTree<int> test;
    test.addElement(20);
    test.addElement(10);
    test.addElement(50);
    test.addElement(5);
    test.addElement(15);
    test.addElement(35);

    test.prettyPrint(cout);

    test.removeElement(10);
    cout<<("--------------------\n");
    test.prettyPrint(cout);
}
