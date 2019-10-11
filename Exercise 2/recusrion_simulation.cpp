#include<iostream>
#include<stack>

using namespace std;

unsigned fact(int n){
    if(n<2){
        return 1;
    } else {
        return n*fact(n-1);
    }
}

unsigned fact_stack(int n){
    stack<int> st;
    while(n){
        st.push(n);
        n--;
    }
    int result = 1;
    while(!st.empty()){
        result*=st.top();
        st.pop();
    }
    return result;
}

int main(){
    cout<<fact(4);
    cout<<endl<<fact_stack(5);
}
