// Array implementation of queue
#include <iostream>
using namespace std;

class MyQueue
{
private:
    int capacity;
    int size;
    int front;
    int rear;
    int *a;

public:
    MyQueue(int n)
    {
        capacity = n;
        size = 0;
        front = rear = -1;
        a = new int[n];
    }

    void enque(int x)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            a[++rear] = x;
            if (front == -1)
            {
                front++;
            }
            size++;
        }
    }

    int deque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int res = a[0];
            if (size == 1)
            {
                front--;
            }
            else
            {
                for (int i = 1; i < size; i++)
                {
                    a[i - 1] = a[i];
                }
            }
            rear--;
            size--;
            return res;
        }
    }

    int getFront()
    {
        return front;
    }
    
    int getRear()
    {
        return rear;
    }

    bool isFull()
    {
        return (size==capacity);
    }

    bool isEmpty()
    {
        return (size==0);
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    MyQueue q(5);

    cout<<"Queue is empty: "<<q.isEmpty()<<endl;
    q.enque(7);
    q.enque(45);

    q.enque(1);
    cout<<"Front and rear after 3 enque : "<<q.getFront()<<" "<<q.getRear()<<endl;

    q.enque(9);
    cout<<"Size of queue after enque 4 elements : "<<q.getSize()<<endl;

    q.enque(17);
    q.enque(3);
    cout<<"Queue is full : "<<q.isFull()<<endl;

    cout<<"Now queue has => 7 45 1 9 17 "<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<"Front and rear after all dequeue : "<<q.getFront()<<" "<<q.getRear()<<endl;
    cout<<q.deque()<<endl;

    return 0;
}