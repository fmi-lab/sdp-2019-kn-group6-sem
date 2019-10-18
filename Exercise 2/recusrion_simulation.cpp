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

unsigned fact_stack2(int n)
{
    stack<int> st;
    st.push(n);
    int result = 1;
    while(!st.empty())
    {
        int current = st.top();
        st.pop();
        if(current > 0)
        {
            result *= current;
            st.push(current-1);
        }
    }
    return result;
}

int main(){
    cout<<fact(4)<<endl;
    cout<<fact_stack(5)<<endl;
    cout<<fact_stack2(5)<<endl;
}
