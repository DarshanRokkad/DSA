// Implementation of deque using circular array
#include <iostream>
using namespace std;

class MyDeqeue
{
private:
    int *a;
    int size;
    int capacity;
    int front;
    int rear;

public:
    MyDeqeue(int n)
    {
        capacity = n;
        size = 0;
        front = -1;
        rear = 0;
        a = new int[n];
    }

    bool isEmpty()
    {
        // return (size==0);
        return (front == -1);
    }
    bool isFull()
    {
        // return (size==capacity);
        return ((rear == capacity - 1 && front == 0) || rear == front - 1);
    }

    int getFront()
    {
        if (size == 0)
        {
            return INT_MIN;
        }
        else
        {
            return front;
        }
    }
    int getRear()
    {
        if (size == 0)
        {
            return 0;
        }
        else
        {
            return rear;
        }
    }

    void insertfront(int x)
    {
        if (isFull())
        {
            cout << "Overflow condition!.." << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }
        a[front] = x;
        size++;
    }
    void insertrear(int x)
    {
        if (isFull())
        {
            cout << "Overflow condition!.." << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        a[rear] = x;
        size++;
    }
    void deletefFront()
    {
        if (isEmpty())
        {
            cout << "Underflow condition!.." << endl;
            return;
        }
        if (rear == front)
        {
            front = -1;
            rear = 0;
        }
        else if (rear == 0)
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }
    }
    void deleterear()
    {
        if (isEmpty())
        {
            cout << "Underflow condition!.." << endl;
            return;
        }
        if (rear == front)
        {
            front = -1;
            rear = 0;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

int main()
{
    MyDeqeue dq(5);
    cout << "Insert element at rear end  : 5 \n";
    dq.insertrear(5);

    cout << "insert element at rear end : 10 \n";
    dq.insertrear(10);

    cout << "inserting element at front end : 15\n";
    dq.insertfront(15);

    cout << "inserting element at front end : 20\n";
    dq.insertfront(20);

    cout << "inserting element at front end : 13\n";
    dq.insertfront(13);

    dq.deleterear();
    dq.deleterear();
    dq.deleterear();

    return 0;
}