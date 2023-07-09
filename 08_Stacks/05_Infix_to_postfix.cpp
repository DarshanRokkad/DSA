// Convert infix to postfix
#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return -1;
}

bool isOperator(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    default:
        return false;
    }
    return -1;
}

string convertIntoPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((st.top() != '(') && (!st.empty()))
            {
                postfix += st.top();
                st.pop();
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (st.empty())
            {
                st.push(infix[i]);
            }
            else if (precedence(st.top()) < precedence(infix[i]))
            {
                st.push(infix[i]);
            }
            else
            {
                while ((!st.empty()) && (precedence(st.top()) >= precedence(infix[i])))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix ;
    cout<<"Enter the infix expression : ";
    // a+b*c-d/e
    getline(cin,infix);
    string postfix = convertIntoPostfix(infix);
    cout << "Infix : " << infix << endl;
    cout << "Postfix : " << postfix << endl;

    return 0;
}