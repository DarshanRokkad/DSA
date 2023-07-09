// Linked list implementation of stack at top
// i.e insert at the top and delete at the top not at the end
#include <iostream>
using namespace std;

template <class T>
class node
{
private:
    T data;
    node *next;

public:
    template <class>
    friend class MyStack;
    node(T x)
    {
        data = x;
        next = NULL;
    }
};

template <class T>
class MyStack
{
private:
    node<T> *top;

public:
    MyStack()
    {
        top = NULL;
    }

    void push(T x)
    {
        cout << x << " is pushed to stack." << endl;
        node<int> *temp = new node<int>(x);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << top->data << " is poped from stack." << endl;
            T res = top->data;
            node<int> *p = top;
            top = top->next;
            delete p;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return (top->data);
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack : " << endl;
            node<int> *p = top;
            while (p)
            {
                cout << p->data << endl;
                p = p->next;
            }
            cout << endl;
        }
    }

    bool isEmpty()
    {
        return (top == NULL);
    }
};

int main()
{
    MyStack<int> s;
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(45);
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    s.pop();
    s.display();

    return 0;
}