#include<list>
#include<iostream>

using namespace std;

template <typename T>
void print_list(const list<T>& l){
    typename list<T>::const_iterator it = l.begin();
    for(; it!=l.end(); it++){
        cout<<*it<<' ';
    }
    cout<<endl;
}

template <typename T>
void merge_lists(const list<T>& l1, const list<T>& l2, list<T>& result){
    result.clear();

    typename list<T>::const_iterator it1 = l1.begin();
    typename list<T>::const_iterator it2 = l2.begin();

    while(it1 != l1.end() && it2 != l2.end()){
        if(*it1 < *it2){
            result.push_back(*it1);
            it1++;
        } else {
            result.push_back(*it2);
            it2++;
        }
    }
    while(it1 != l1.end()){
        result.push_back(*it1);
        it1++;
    }
    while(it2 != l2.end()){
        result.push_back(*it2);
        it2++;
    }
}

template <typename T>
void merge_sort(const list<T>& l, list<T>& result){

//    result.clear();

//    cout<<l.size()<<endl;

    typename list<T>::const_iterator it = l.begin();

    list<T> l1, l2;

    while(it != l.end()){
        l1.push_back(*it);
        it++;
        if(it != l.end()){
            l2.push_back(*it);
            it++;
        }
    }

    print_list(l1);
    print_list(l2);

    if(l1.size() != 1){
        merge_sort(l1, l1);
    }
    if(l2.size() != 1){
        merge_sort(l2, l2);
    }
    merge_lists(l1, l2, result);

    cout<<"result = ";
    print_list(result);
}


int main(){
    list<int> l1, l2, l3;

    l1.push_back(5);
    l1.push_back(10);
    l1.push_back(15);
    l1.push_back(20);
    l1.push_back(25);
    l1.push_back(30);

    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(8);
    l2.push_back(16);
    l2.push_back(24);
    l2.push_back(32);

//    print_list(l1);
//    print_list(l2);

    merge_lists(l1, l2, l3);
//    print_list(l3);

    list<int> unsorted_list;

    unsorted_list.push_back(20);
    unsorted_list.push_back(5);
    unsorted_list.push_back(-20);
    unsorted_list.push_back(42);
    unsorted_list.push_back(7);
    unsorted_list.push_back(18);
    unsorted_list.push_back(0);

    list<int> sorted;

    merge_sort(unsorted_list, sorted);

    print_list(sorted);
}
