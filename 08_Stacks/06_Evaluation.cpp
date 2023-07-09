// Evaluation of postfix
#include <iostream>
#include <stack>
using namespace std;

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

int evaluate(int x, int y, char op)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '^':
        return x ^ y;
    }
    return -1;
}

int evaluation(string po)
{
    stack<int> st;
    for (int i = 0; i < po.length(); i++)
    {
        if (isOperator(po[i]))
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(evaluate(b, a, po[i]));
        }
        else if( po[i]>='0'&& po[i]<='9')
        {
            st.push(po[i]-'0');
        }
    }
    int r = st.top();
    st.pop();

    return r;
}

int main()
{
    // 35*62/+4-
    string postfix;
    cout << "Enter the postfix expression : ";
    getline(cin, postfix);
    int answer = evaluation(postfix);
    cout << postfix << " = " << answer << endl;

    return 0;
}