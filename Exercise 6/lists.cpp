#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
struct node
{
    T value;
    node<T>* next;

    node(const T& value = T(), node<T>* next= NULL): value(value), next(next) {}
//    node(const node<T>*& other){
//        cout<<"node(other)/n";
//        node<T>* temp = &other;
//        node<T>* dis = this;
//        value = temp->value;
//        while(temp){
//            cout<<temp->value<<' ';
//            temp = temp->next;
//            node<T>* nod = new node<T>(temp->value, NULL);
//            dis->next = nod;
//            dis = nod;
//        }
//    }
};

template <typename T>
size_t length(node<T>* l)
{
    node<T>* temp = l;
    size_t i = 0;
    while(temp)
    {
        i++;
    }
    return i;
}

template <typename T>
void copy_from (node<T>* l, size_t pos, size_t n, node<T>* result)
{
    node<T>* temp = l;

    for(int i = 0; i<pos && temp; i++)
    {
        temp = temp->next;
    }
    result->value = temp->value;
    temp = temp->next;
    for(int i = 0; i<n-1 && temp; i++)
    {
//        cout<<result->value<<' ';
        result -> next = new node<T>(temp->value);
        result = result->next;
        temp = temp->next;
    }
}

template <typename T>
void delete_list(node<T>* l)
{
    l = l->next;
    node<T>* temp = l->next;
    do
    {
        cout<<l->value<<' ';
        delete l;
        l = temp;
        temp = temp->next;
    }
    while(temp);
    cout<<l->value;
    delete l;
}

template <typename T>
void split(node<T>* l, node<T>* l1, node<T>* l2){
    size_t len = length(l);
    copy_from(l, 0, len/2, l1);
//    copy_from(l, len/2 + 1, ceil(len/2), l2);
}

int main()
{
    node<int> a(1), b(2), c(3), d(4), z(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &z;

//    node<int> e((const node<int>*)&a);

//    cout<<a.value<<endl;
    node<int> e;

    copy_from(&a, 1, 4, &e);

    node<int>* ep = &e;
    while(ep){
        cout<<ep->value<<' ';
        ep = ep->next;
    }
    cout<<endl;
    delete_list(ep);

    node<int> l1, l2;
//    split(&a, &l1, &l2);

//
//    while(ep){
//        cout<<ep->value<<' ';
//        ep = ep->next;
//    }
}
