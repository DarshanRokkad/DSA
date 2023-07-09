// Implementation of stack using class
#include <iostream>
using namespace std;
template <class T>
class MyStack
{
private:
    int capacity;
    int top;
    T *arr;

public:
    // constructor to intialise the stack
    MyStack(int n)
    {
        capacity = n;
        top = -1;
        arr = new T[n];
    }

    // To push the element into the stack
    void push(T x)
    {
        if (top == (capacity - 1))
        {
            cout << "Overflow condition." << endl;
        }
        else
        {
            cout << "Element to pushed to stack succesfully." << endl;
            arr[++top] = x;
        }
    }

    // To pop the element from the stack and returns the poped value
    T pop()
    {
        if (top == -1)
        {
            cout << "Underflow condition." << endl;
            return -1;
        }
        else
        {
            cout << "Element is poped from stack succesfully." << endl;
            return arr[top--];
        }
    }

    // Displaying stack
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "**Stack**" << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "*** Stack ***" << endl;
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    MyStack<float> S(n);

    while (1)
    {
        cout << endl;
        cout << "*** Stack operations. ***" << endl;
        cout << "1. Push operation." << endl;
        cout << "2. Pop operation. " << endl;
        cout << "3. Display. " << endl;
        cout << "4. Exit. " << endl;
        cout << "Enter the choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the data to be pushed : ";
            float data;
            cin >> data;
            S.push(data);
            S.display();
            break;
        }
        case 2:
        {
            float poped_data = S.pop();
            if (poped_data != -1)
                cout << poped_data << " is poped from stack." << endl;
            S.display();
            break;
        }
        case 3:
            S.display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Please enter valid choice." << endl;
        }
    }

    return 0;
}