// Circular linked list
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class circularLL
{
private:
    node *head;
    int size;

public:
    circularLL()
    {
        head = NULL;
    }

    // creating the circular linked list
    void create(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            InsertEnd(a[i]);
        }
    }

    // inserting node at the begining of circular linked list
    void InsertBegin(int x)
    {
        cout << x << " is inserted begining." << endl;
        node *temp = new node(x);
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            // inserting at begining in constant time
            node *temp = new node(x);
            temp->next = head->next;
            head->next = temp;
            int q = head->data;
            head->data = head->next->data;
            head->next->data = q;
        }
        size++;
        display();
    }

    // inserting node at the end of the circular linked list
    void InsertEnd(int x)
    {
        cout << x << " is inserted end." << endl;
        node *temp = new node(x);
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            // inserting at end in constant time
            node *temp = new node(x);
            temp->next = head->next;
            head->next = temp;
            int q = head->data;
            head->data = head->next->data;
            head->next->data = q;
            head = head->next;
        }
        size++;
        display();
    }

    // Deleting first node form circular linked list
    void deleteFirst()
    {
        if(head==NULL)
        {
            cout<<"Linked list empty."<<endl;
        }
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            cout << "Deleted first node." << endl;
            // deleting at begining in constant time
            node *temp = head->next;
            head->data = head->next->data;
            head->next = head->next->next;
            delete temp;
        }
        display();
    }

    // Deleting last node form circular linked list
    void deleteLast()
    {
        if(head==NULL)
        {
            cout<<"Linked list empty."<<endl;
        }
        if (head == NULL)
        {
            cout << "Circular linked list empty." << endl;
        }
        else if (head->next == head)
        {
            cout << "Deleted last node." << endl;
            delete head;
            head = NULL;
        }
        else
        {
            cout << "Deleted last node." << endl;
            // deleting at end in linear time
            node *last_second = head;
            while (last_second->next->next != head)
            {
                last_second = last_second->next;
            }
            node *last = last_second->next;
            last_second->next = head;
            delete last;
        }
        display();
    }

    void deleteAt(int pos)
    {
        if (size == 0)
        {
            cout << "Circular linked list is empty." << endl;
        }
        else
        {
            if (pos >= 1 && pos <= size)
            {
                cout << "Delete at position " << pos << endl;
                if (pos == 1)
                {
                    deleteFirst();
                }
                else
                {
                    node *p = head;
                    for (int i = 1; i < pos - 1; i++)
                    {
                        p = p->next;
                    }
                    node *temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
                if (pos != 1)
                    display();
            }
            else
            {
                cout << "Position out of range." << endl;
            }
        }
    }

    // displaying the circular linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty." << endl;
        }
        else
        {
            cout << "Circular linked list : ";
            node *p = head;
            do
            {
                cout << p->data << " ";
                p = p->next;
            } while (p != head);
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    int arr[] = {2, 3, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    circularLL c;
    c.create(arr, size);
    c.InsertBegin(23);
    c.InsertEnd(34);
    c.deleteAt(3);
    c.deleteAt(1);
    c.deleteFirst();
    c.deleteLast();
    c.deleteFirst();
    c.deleteLast();

    return 0;
}