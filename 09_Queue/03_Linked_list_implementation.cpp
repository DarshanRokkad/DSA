// Queue implementation using linked list
#include <iostream>
using namespace std;

template <class t>
class node
{
    t data;
    node<t> *next;

public:
    template <class>
    friend class MyQueue;
    node(t x)
    {
        data = x;
        next = NULL;
    }
};

template <class t>
class MyQueue
{
private:
    node<t> *front;
    node<t> *rear;

public:
    MyQueue()
    {
        front = NULL;
        rear = NULL;
    }

    void enque(t x)
    {
        cout << x << " is enqueued to queue." << endl;
        node<t> *temp = new node<t>(x);
        if (isEmpty())
        {
            rear = front = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
    }

    void deque()
    {
        if (isEmpty())
        {
            cout << "No nodes." << endl;
        }
        else
        {
            cout << front->data << " is dequed from the queue." << endl;
            node<t> *temp = front;
            front = front->next;
            delete temp;
            if (!front)
                rear = NULL;
        }
    }

    bool isEmpty()
    {
        return (!front);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Queue." << endl;
        }
        else
        {
            cout << "Queue : ";
            node<t> *temp = front;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl<<endl;
        }
    }
};

int main()
{
    MyQueue<int> q;
    q.enque(5);
    q.enque(6);
    q.enque(9);
    q.enque(45);
    q.display();

    q.deque();
    q.display();

    q.deque();
    q.display();

    q.deque();
    q.display();

    q.deque();
    q.display();

    return 0;
}