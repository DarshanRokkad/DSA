/*
Design a C++ program to evaluate a valid postfix expression using stack.
Assume that the postfix expression is read as a single line consisting of non-
negative single digit operands and binary operators. The operators are +, -,
*, / and $.
*/

#include <iostream>
#include <stack>
#include<math.h>
using namespace std;

class check
{
private:
    string postfix;

public:
    check()
    {
        input();
        cout << "Answer is " << evaluate();
    }
    void input()
    {
        cout << "Enter the postfix expression : ";
        getline(cin,postfix);
    }
    int compute(int x, int y, char operat)
    {
        int result = 0;
        switch (operat)
        {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '$':
            result = pow(x,y);
            break;
        }
        return result;
    }
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }
    int evaluate()
    {
        stack<int> st;
        for (int i = 0; i < postfix.length(); i++)
        {
            if (postfix[i] >= '0' && postfix[i] <= '9')
            {
                st.push((postfix[i] - '0'));
            }
            else if (isOperator(postfix[i]))
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = compute(op2, op1, postfix[i]);
                st.push(ans);
            }
        }
        int resu = st.top();
        st.pop();
        return resu;
    }
};

int main()
{
    check c;

    return 0;
}