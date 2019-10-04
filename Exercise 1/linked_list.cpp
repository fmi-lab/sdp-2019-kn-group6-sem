#include "linked_list.h"

template <typename T>
linked_list<T>::linked_list(): first(NULL), last(NULL), current(NULL) {}

template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other): current(NULL)
{
    node<T>* p = other.first;
    node<T>* previous = p;
    while(p)
    {
        node<T>* q = new(node<T>);
        q->value = p->value;
        if(previous != p)
        {
            previous->next = q;
        }
        else
        {
            first = q;
        }
        q->next = NULL;
        previous = q;
        last = q;
        p = p->next;
    }
}

template <typename T>
linked_list<T>::~linked_list()
{
    current = first;
    node<T>* next;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& other)
{
    if(this != &other)
    {
        node<T>* cur = first;
        node<T>* next;
        while(cur)
        {
            next = cur->next;
            delete cur;
            cur = next;
        }

        node<T>* p = other.first;
        node<T>* previous = p;
        while(p)
        {
            node<T>* q = new(node<T>);
            q->value = p->value;
            if(previous != p)
            {
                previous->next = q;
            }
            else
            {
                first = q;
            }
            if(p == other.current){
                current = q;
            }
            q->next = NULL;
            previous = q;
            last = q;
            p = p->next;
        }
    }
    return *this;
}

template <typename T>
void linked_list<T>::start_iter(){
    current = first;
}

template <typename T>
void linked_list<T>::next(){
    current = current->next;

}

template <typename T>
T& linked_list<T>::get_current() const{
    return current->value;
}

template <typename T>
void linked_list<T>::add_last(const T& val){
    node<T>* p = new node<T>;
    p->value = val;
    p->next = NULL;
    last->next = p;
    last = last->next;
}


template <typename T>
void linked_list<T>::add_element_at(const T& val, const size_t& pos){
    node<T>* p = first;

    for(size_t iter = 0; iter<pos-2; iter++){
        p=p->next;
    }
    node<T>* q = new node<T>;
    q->value = val;
    q->next = p->next;
    if(p == first){
        first = q;
    } else {
        p->next = q;
    }
}

int main() {

}












