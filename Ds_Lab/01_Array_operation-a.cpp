// Performing the array operations in c++ using class and objects
#include <iostream>
using namespace std;
class ArrayOperation
{
private:
    int max;
    int size;
    int *a;

public:
    ArrayOperation(int m)
    {
        max = m;
        size = 0;
        a = new int[m];
        while (1)
        {
            cout << endl;
            cout << "Array operations" << endl;
            cout << "1. Create the array ." << endl;
            cout << "2. Display the array . " << endl;
            cout << "3. Insert the element of the array ." << endl;
            cout << "4. Delete the element from an array ." << endl;
            cout << "5. Exit." << endl;
            int choice;
            cout << "Enter the choice : ";
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insertele();
                break;
            case 4:
                deleteele();
                break;
            case 5:
                exit(0);
            }
        }
    }
    void create()
    {
        cout << "Enter the number elements in the array : ";
        cin >> size;
        cout << "Enter the elements of the array : ";
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
        display();
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Array is empty" << endl;
        }
        else
        {
            cout << "Array : ";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    void insertele()
    {
        if (size != 0)
        {
            int pos;
            cout << "Enter the position you need to insert an element : ";
            cin >> pos;
            if (pos >= 0 && pos <= size)
            {
                int ele;
                cout << "Enter the element you need to insert : ";
                cin >> ele;
                int i = size;
                for (; i > pos; i--)
                {
                    a[i] = a[i - 1];
                }
                a[i] = ele;
                size++;
                display();
            }
            else
            {
                cout << "The index is out of range " << endl;
            }
        }
        else
        {
            cout << "Array is not present please create the array." << endl;
        }
    }

    void deleteele()
    {
        if (size != 0)
        {
            int pos;
            cout << "Enter the position you need to delete an element : ";
            cin >> pos;
            if (pos >= 0 && pos < size)
            {
                for (int i = pos; i < size - 1; i++)
                {
                    a[i] = a[i + 1];
                }
                size--;
                display();
            }
            else
            {
                cout << "The index is out of range " << endl;
            }
        }
        else
        {
            cout << "Array is not present please create the array." << endl;
        }
    }
};

int main()
{
    ArrayOperation a(50);

    return 0;
}