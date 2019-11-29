#define DOCTEST_CONFIG_IMPLEMENT

//#include "doctest.h"
#include "bintree.h"
#include "bintree.hpp"


//#include "tree_tests.hpp"

int main ()
{
    BinTree<int> test;
    test.addElement ("",7);
    test.addElement ("L",30);
    test.addElement ("LR",12);
    test.addElement ("LRL",90);
    test.addElement ("R",5);
    test.addElement ("RL",50);
    test.mirrorTree().prettyPrint(cout);



}
