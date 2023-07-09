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
        front = -1;
        rear = -1;
        a = new T[n];
        while (1)
        {
            menu();
        }
    }
    void menu()
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1. Insert an character in the Circular queue." << endl;
        cout << "2. Delete an Character in the Circular queue." << endl;
        cout << "3. Display Circular queue ." << endl;
        cout << "4. Exit ." << endl;
        cout << "Enter the choice  : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Character to be inserted : ";
            T x;
            cin >> x;
            enque(x);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
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
            cout << "Queue is full." << endl
                 << endl;
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            cout << x << " is enqued to array." << endl;
            rear = (rear + 1) % capacity;
            a[rear] = x;
            size++;
        }
        display();
    }

    void deque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl
                 << endl;
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
        }
        else
        {
            cout << "Circular queue : ";
            int f = front;
            int r = (rear + 1) % capacity;
            do
            {
                cout << a[f] << " ";
                f = (f + 1) % capacity;
            } while (f != r);
            cout << endl;
        }
        cout << "Size : " << size << endl;
        cout << "Front : " << front << endl;
        cout << "Rear : " << rear << endl;
        cout << endl;
    }
};

int main()
{
    cout << "**Circular queue**" << endl;
    cout << "Enter the size of Queue : ";
    int size;
    cin >> size;
    MyQueue<char> q(size);

    return 0;
}