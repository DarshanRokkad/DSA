// Implementation of doubly end queue using doubly linked list
#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int x)
    {
        prev = NULL;
        data = x;
        next = NULL;
    }
};

class MyDeque
{
private:
    int size;
    node *head;
    node *last;

public:
    MyDeque()
    {
        size = 0;
        head = NULL;
        last = NULL;
    }
    void insertFront(int x)
    {
        node *temp = new node(x);
        if (isEmpty())
        {
            last = head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertRear(int x)
    {
        node *temp = new node(x);
        if (isEmpty())
        {
            last = head = temp;
        }
        else
        {
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        size++;
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
        }
        else
        {
            node *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
            size--;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
        }
        else
        {
            cout << "Deque : ";
            node *temp = head;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int getsize()
    {
        return size;
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return (size - 1);
        }
    }
    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    MyDeque dq;
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(30);
    dq.insertRear(50);
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    dq.display();

    return 0;
}