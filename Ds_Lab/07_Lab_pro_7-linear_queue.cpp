/* Design a C++ Program to perform the following operations on Linear Queue
of Integers (Array Implementation of Queue with maximum size MAX)
a. Insert an Element to a Linear Queue.
b. Delete an Element from the Linear Queue.
c. Demonstrate Overflow and Underflow situations on Linear Queue
d. Display the status of Linear Queue */
#include <iostream>
using namespace std;
class MyQueue
{
private:
    int max_size;
    int arr_size;
    int *a;

public:
    MyQueue(int n)
    {
        max_size = n;
        arr_size = 0;
        a = new int[max_size];
        while (1)
        {
            menu();
        }
    }
    void menu()
    {
        cout << endl;
        cout << "1. Insert an element in the linear queue." << endl;
        cout << "2. Delete an element in the linear queue." << endl;
        cout << "3. Display queue ." << endl;
        cout << "4. Exit ." << endl;
        cout << "Enter the choice  : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted : ";
            int x;
            cin >> x;
            insert(x);
            break;
        case 2:
            delete_element();
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
    // inserting element into linear queue i.e inserting at the end of the array
    void insert(int x)
    {
        if (arr_size == max_size)
        {
            cout << "Overflow condition." << endl;
        }
        else
        {
            cout << "Element is inserted linear queue successfully." << endl;
            a[arr_size++] = x;
        }
        display();
    }
    // Deleting element from the linear queue i.e deleting elment from the front of the array
    void delete_element()
    {
        if (arr_size == 0)
        {
            cout << "Underflow condition." << endl;
        }
        else
        {
            cout << "Element is deleted from linear queue successfully." << endl;
            // shifting elements of the array 1 position backward
            for (int i = 1; i < arr_size; i++)
            {
                a[i - 1] = a[i];
            }
            arr_size--;
            display();
        }
    }
    // Displays the elements present in the queue
    void display()
    {
        if (arr_size == 0)
        {
            cout << "Array is empty." << endl;
        }
        else
        {
            cout << "Linear queue : ";
            for (int i = 0; i < arr_size; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "*** Linear queue ***" << endl;
    int n ;
    cout << "Enter the maximum size of the queue : ";
    cin >> n;
    MyQueue q(n);

    return 0;
}