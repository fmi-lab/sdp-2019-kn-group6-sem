#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
using namespace std;

bool number(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool oper(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}

unsigned weight(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}

void translate(const char* str, string& res)
{
    res.clear();
    stack<char> stac;
    for(int i = 0; str[i]; i++)
    {
        if(number(str[i]))
        {
            cout<<str[i];
            res += str[i];
        }
        else if(oper(str[i]))
        {
            while(!stac.empty() && weight(stac.top()) < weight(str[i]) && stac.top()!='(')
            {
                cout<<stac.top();
                res += stac.top();
                stac.pop();
            }
            stac.push(str[i]);
        }
        else if(str[i] == '(')
        {
            stac.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!stac.empty() && stac.top() != '(')
            {
                cout<<stac.top();
                res += stac.top();
                stac.pop();
            }
            stac.pop();
        }
    }
    while(!stac.empty())
    {
        cout<<stac.top();
        res += stac.top();
        stac.pop();
    }
}

double calculate(const string& str)
{
    stack<double> container;
    for(const char& c : str)
    {
        if(number(c))
        {
            container.push((c-'0'));
        }
        else if(oper(c))
        {
            double second = container.top();
            container.pop();
            double first = container.top();
            container.pop();
            double result;
            switch (c)
            {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
            case '^':
                result = pow(first, second);
                break;
            }
            container.push(result);
        }
    }
    return container.top();
}

int main()
{
    string str;
    translate("(1+2)*(3-4)^2", str);
    cout<<endl<<calculate(str);
}
