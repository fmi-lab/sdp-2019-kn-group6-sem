#include<iostream>
#include<queue>

using namespace std;

template <typename T>
void min_el_queue(queue<T> q, T& min_el, queue<T>& minless_q){
    min_el = q.front();
    q.pop();

    while(!q.empty()){
        T current = q.front();
        q.pop();
        if(current < min_el){
            minless_q.push(min_el);
            min_el = current;
        } else{
            minless_q.push(current);
        }
    }
}

template <typename T>
void sort_queue(queue<T> q, queue<T>& sorted_queue){

    while(!q.empty()){
        queue<T> temporary;
        T min_el;
        min_el_queue(q, min_el, temporary);
        q = temporary;
        sorted_queue.push(min_el);
    }
}

template <typename T>
void queue_merger(queue<T> q1, queue<T> q2, queue<T>& merged){
    while(!q1.empty() && !q2.empty()){
        if(q1.front() < q2.front()){
            merged.push(q1.front());
            q1.pop();
        } else {
            merged.push(q2.front());
            q2.pop();
        }
    }
    while(!q1.empty()){
        merged.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        merged.push(q2.front());
        q2.pop();
    }
}

template <typename T>
void print_queue(queue<T> q){
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(23);
    q.push(11);
    q.push(0);
    q.push(-5);
    q.push(42);
    q.push(8);

    queue<int> sorted_q;
    sort_queue(q, sorted_q);
    print_queue(sorted_q);

    queue<int> q2;
    q2.push(2);
    q2.push(0);
    q2.push(20);
    q2.push(220);
    q2.push(18);
    q2.push(-32);

    queue<int> sorted_q2;
    sort_queue(q2, sorted_q2);
    cout<<"*************\n";
    print_queue(sorted_q2);
    cout<<"*************\n";

    queue<int> merged;
    queue_merger(sorted_q, sorted_q2, merged);
    print_queue(merged);



}
