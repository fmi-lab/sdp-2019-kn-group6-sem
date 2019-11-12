#include<iostream>
using namespace std;

template <typename T>
struct dllnode
{
    T value;
    dllnode<T>* next;
    dllnode<T>* previous;

    dllnode(const T& value = T(), dllnode<T>* next = NULL, dllnode<T>* previous = NULL) : value(value), next(next), previous(previous) {}
};

template <typename T>
int count_x(const dllnode<T>* l, T x)
{
    dllnode<T>* temp = l;
    int counter = 0;
    while(temp)
    {
        if (temp->value == x)
        {
            counter ++;
        }
        temp = temp->next;
    }
}

dllnode<int>* range (int x, int y)
{
    dllnode<int>* l;
    dllnode<int>* temp = new dllnode<int>;
    temp->value = x;
    x++;
    l = temp;
    dllnode<int>* prev;
    prev = temp;
    while(x<=y)
    {
        temp = new dllnode<int>;
        temp->value = x;
        temp->previous = prev;
        prev->next = temp;
        prev = temp;
        x++;
    }
    return l;
}

template <typename T>
void remove_all(dllnode<T>*& l, const T& x)
{
    dllnode<T>* temp = l;
    while(temp)
    {
        if(temp->value == x)
        {
            dllnode<T>* save = temp->next;
            if(temp->previous)
            {
                cout<<"first if\n";
                temp->previous->next = temp->next;
            } else {
                l = temp->next;
            }
            if(temp->next)
            {
                cout<<"second if\n";
                temp->next->previous = temp->previous;
            }
            delete temp;
            temp = save;
        }
        if(temp){
            temp = temp->next;
        }
    }
}

template <typename T>
void remove_duplicates(dllnode<T>*& l){
    dllnode<T>* temp = l;
    while(temp->next){
        remove_all(temp->next, temp->value);
        temp = temp->next;
    }
}

int main()
{
    dllnode<int>* dll = range(1,7);
    dllnode<int>* dll1 = dll;

    dllnode<int>* dll2 = range(1,9);
    while(dll->next)
    {
//        cout<<dll->value<<' ';
        dll = dll->next;
    }

    dll->next = dll2;

    remove_duplicates(dll1);

        while(dll1)
    {
        cout<<dll1->value<<' ';
        dll1 = dll1->next;
    }

//
//    cout<<dll->value<<' ';
//
//    while(dll->previous)
//    {
//        cout<<dll->value<<' ';
//        dll = dll->previous;
//    }
//    cout<<"****************\n";
//
//    removeAll(dll, 1);
//
//    while(dll)
//    {
//        cout<<dll->value<<' ';
//        dll = dll->next;
//    }





}
