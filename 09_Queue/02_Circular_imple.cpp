// Array implementation of queue
#include <iostream>
using namespace std;

template <class T>
class MyQueue
{
private:
    int capacity;
    int size;
    int front;
    int rear;
    T *a;

public:
    MyQueue(int n)
    {
        capacity = n;
        size = 0;
        front = 0;
        rear = capacity - 1;
        a = new T[n];
    }

    bool isFull()
    {
        return (size == capacity);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enque(T x)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            cout << endl;
        }
        else
        {
            if (size == 0)
            {
                front++;
            }
            cout << x << " is enqued to array." << endl;
            rear = (rear + 1) % capacity;
            a[rear] = x;
            size++;
            display();
        }
    }

    void deque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            cout << endl;
        }
        else
        {
            cout << a[front] << " is dequed from array." << endl;
            front = (front + 1) % capacity;
            size--;
            if (size == 0)
            {
                front = -1;
                rear = -1;
            }
            display();
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Array is empty." << endl;
            cout << endl;
        }
        else
        {
            cout << "Circular queue : ";
            int i = front;
            int j = (rear + 1) % capacity;
            do
            {
                cout << a[i] << " ";
                i = (i + 1) % capacity;
            } while (i != j);
            cout << endl;
        }
        cout << "Front : " << front << endl;
        cout << "Rear : " << rear << endl;
        cout << endl;
    }
};

int main()
{
    MyQueue<int> q(5);

    cout << "Queue is empty: " << q.isEmpty() << endl
         << endl;
    q.enque(7);
    q.enque(45);
    q.enque(1);
    q.enque(9);
    q.enque(17);
    q.enque(3);

    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.enque(23);
    q.enque(56);
    q.enque(13);

    return 0;
}