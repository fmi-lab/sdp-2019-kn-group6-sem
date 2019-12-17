#include<iostream>
#include "node.h"
#include<stack>



using namespace std;

bool digit(const char& c){
    if(c >= '0' && c <= '9'){
        return true;
    }
    return false;
}

unsigned oper(const char& c){
    if(c == '*' || c == '/'){
        return 3;
    } else if(c == '+' || c == '-'){
        return 2;
    }
    return 0;
}

node<char>* parseExpression(std::string s){
    stack<node<char>*> st;
    node<char>* open_bracket = new node<char>('(');
    node<char>* close_bracket = new node<char>(')');
    for(const char& c : s){
        if(c == '('){
            st.push(open_bracket);
        }
        else if(digit(c)){
            node<char>* d = new node<char>(c);
            st.push(d);
        }
        else if(oper(c)){
            node<char>* op = new node<char>(c);
            st.push(op);
        } else if(c == ')'){
            node<char>* right = st.top();
            st.pop();
            node<char>* op = st.top();
            st.pop();
            node<char>* left = st.top();
            st.pop();
            st.pop();
            op->left = left;
            op->right = right;
            st.push(op);
        }
    }
    return st.top();
}

double calculate_expression_tree(node<char>* root){
    if(root->data == '+'){
        return calculate_expression_tree(root->left) + calculate_expression_tree(root->right);
    } else if(root->data == '-'){
        return calculate_expression_tree(root->left) - calculate_expression_tree(root->right);
    } else if(root->data == '*'){
        return calculate_expression_tree(root->left) * calculate_expression_tree(root->right);
    } else if(root->data == '/'){
        return calculate_expression_tree(root->left) / calculate_expression_tree(root->right);
    } else if (digit(root->data)){
        return root->data - '0';
    }
}

int main(){
    node<char>* exp;
    exp = parseExpression("((2*(3-1))/2)");
    print_tree(exp);
    cout<<calculate_expression_tree(exp);
}
