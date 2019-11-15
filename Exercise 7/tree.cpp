#include "tree.h"

template <typename T>
Tree<T>::Tree(const T& value, const int& weight): value(value), weight(weight){}

template <typename T>
void Tree<T>::add_node(const T& value, const int& weight){
    Tree<T>* new_node = new Tree<T>(value, weight);
    children.push_back(new_node);
}

template <typename T>
void Tree<T>::remove_children(){
    for(Tree<T>* child : children){
        child->remove_children();

        delete child;
    }
    children.clear();
}

//template <typename T>
//void Tree<T>::remove_tree(const Tree<T>* node){
//    node->remove_children();
//    children.erase(node);
//    delete node;
//}

template <typename T>
void Tree<T>::remove_nth_child_tree(const size_t& pos){
    children[pos]->remove_children();
    children.erase(children.begin() + pos);
}

template <typename T>
Tree<T>::~Tree(){
    remove_children();
    children.clear();
}

template <typename T>
void Tree<T>::print_tree(int layer)const{
    for(int i = 0; i<layer; i++){
        cout<<'\t';
    }
    cout<<'('<<value<<", "<<weight<<")\n";
    ++layer;
    for(const Tree<T>* child : children){
        child->print_tree(layer);
    }
}

template <typename T>
void Tree<T>::copy(const Tree<T>& other){
    value = other.value;
    weight = other.weight;
    for(const Tree<T>* child : other.children){
        Tree<T>* new_child = new Tree<T>(child->value, child->weight);
        children.push_back(new_child);
        new_child->copy(*child);
    }
}

template <typename T>
Tree<T>::Tree(const Tree<T>& other): value(other.value), weight(other.weight){
    copy(other);
}

template <typename T>
void Tree<T>::add_tree(const Tree<T>& tree){
    Tree<T>* new_tree = new Tree<T>(tree);
    children.push_back(new_tree);
}

int main(){
    Tree<int> t1(0, 0);
    Tree<int> t2(1, 5);
    Tree<int> t3(2, 10);
    Tree<int> t4(3, 15);
    Tree<int> t5(4, 20);
    Tree<int> t6(5, 25);
    Tree<int> t7(6, 30);

    t6.add_tree(t7);
    t5.add_tree(t6);
    t5.add_node(7, 35);
    t2.add_tree(t5);
    t1.add_tree(t2);
    t3.add_node(8, 40);
    t1.add_tree(t3);

    t1.print_tree();

    t1.remove_nth_child_tree(0);

    t1.print_tree();
}
