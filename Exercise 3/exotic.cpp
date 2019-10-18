#include<queue>
#include<iostream>

using namespace std;

struct Person{
    string name;
    unsigned id;
    static unsigned incrementator;

    Person(): name("Unnamed"), id(incrementator){
        incrementator++;
    }

    bool operator<(const Person& other) const{
        return id < other.id;
    }

    bool operator>(const Person& other) const{
        return id > other.id;
    }

    friend ostream& operator<<(ostream& stream, const Person& p);
};

ostream& operator<<(ostream& stream, const Person& p){
    cout<<p.name<<endl;
    cout<<p.id<<endl;
}

unsigned Person::incrementator = 1;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main(){
    deque<int> dq;

    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);

//    cout<<dq.front()<<endl;
//    cout<<dq.back();

    priority_queue<int, std::vector<int>, std::greater<int>> pq;

    pq.push(5);
    pq.push(50);
    pq.push(-25);
    pq.push(10);
    pq.push(52);
    pq.push(3);

    print_queue(pq);

    Person p1, p2, p3, p4;

    priority_queue<Person,  std::vector<Person>, std::greater<Person> > pqp;
    pqp.push(p3);
    pqp.push(p1);
    pqp.push(p4);
    pqp.push(p2);

    print_queue(pqp);


}
