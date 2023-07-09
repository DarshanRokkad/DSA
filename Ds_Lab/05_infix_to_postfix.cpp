/*
Design a C++ program to convert and print a given valid parenthesized infix
arithmetic expression to postfix expression. The expression consists of
single character operands and binary operators +, -, *, / and $. Apply the
concept of stack data structure to solve this problem.
*/

#include <iostream>
#include <stack>
using namespace std;

class Convert
{
private:
    string infix;
    string postfix;
    stack<char> st;

public:
    Convert()
    {
        infix = "";
        postfix = "";
        input();
        InfixToPostfix();
        cout << "Postfix Expression : " << postfix << endl;
    }
    void input()
    {
        cout << "Enter a Infix Expression : ";
        getline(cin, infix);
    }
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }
    bool isOperand(char ch)
    {
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
    int precedence(char c)
    {
        if (c == '$')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    void InfixToPostfix()
    {
        for (int i = 0; i < infix.length(); i++)
        {
            if (isOperand(infix[i]))
            {
                postfix += infix[i];
            }
            else if (infix[i] == '(')
            {
                st.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while ((st.top() != '('))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if (isOperator(infix[i]))
            {
                while ((!st.empty()) && (precedence(infix[i]) <= precedence(st.top())))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }
    }
};

int main()
{
    Convert c;

    return 0;
}