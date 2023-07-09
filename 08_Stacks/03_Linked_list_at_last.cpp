// Linked list implementation of stack at last 
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
} *head = NULL, *last = NULL;

class MyStack
{
private:
    int top;
    int Capacity;

public:
    MyStack(int n)
    {
        top = -1;
        Capacity = n;
    }

    node *new_node(int x)
    {
        node *n = new node();
        n->data = x;
        n->next = NULL;
        return n;
    }

    void push(int x)
    {
        if (top == (Capacity - 1))
        {
            cout << "Stack is full." << endl;
        }
        else
        {
            node *p = new_node(x);
            if (top == -1)
            {
                last = head = p;
            }
            else
            {
                last->next = p;
                last = last->next;
            }
            top++;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else
        {
            node *p = head, *q = NULL;
            while (p->next != NULL)
            {
                q = p;
                p = p->next;
            }
            if (p != head)
            {
                q->next = NULL;
                last = q;
            }
            else
            {
                head = NULL;
            }
            int res = p->data;
            delete p;
            top--;
            return res;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return (last->data);
        }
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int size()
    {
        return (top + 1);
    }
};

int main()
{
    MyStack s(3);
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(45);
    cout << "Size : " << s.size() << endl;
    cout << s.pop() << " is poped." << endl;
    cout << "peek : " << s.peek() << endl;
    cout << s.pop() << " is poped." << endl;
    cout << s.pop() << " is poped." << endl;
    cout << s.pop() << " is poped." << endl;

    return 0;
}