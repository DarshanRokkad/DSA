/*
Design a C++ program using Circular single linked list with header nodes to
perform the following operations
a. To create a circular linked list to represent unsigned long integers
b. To add two long integers represented by circular linked list and store the result in another circular linked list.
c. Display the resultant circular linked list.
*/
#include <iostream>
using namespace std;

class node
{
private:
    unsigned long data;
    node *next;
    friend class CircularLinkedList;

public:
    node(unsigned long d)
    {
        data = d;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    // Creating a circcular linked list
    void create()
    {
        cout << "Enter the head data : ";
        unsigned long da;
        cin >> da;
        node *tem = new node(da);
        tem->next = tem;
        head = tem;
        node *last = head;
        while (true)
        {
            cout << "Enter the data to be inserted(Enter 0 to terminate) : ";
            cin >> da;
            if (da == 0)
                break;
            tem = new node(da);
            tem->next = head;
            last->next = tem;
            last = tem;
        }
        display();
    }

    // displaying linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "Circular linked list don't exist." << endl;
            return;
        }
        node *p = head;
        cout << "Circular linked list : ";
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl
             << endl;
    }

    void add(node *f, node *s)
    {
        if (f == NULL && s == NULL)
        {
            cout << "No Circular linked list is present." << endl;
        }
        else
        {
            node *t;
            unsigned long sum = 0;
            node *head1 = f, *head2 = s;

            if (f && s)
            {
                sum = (f->data) + (s->data);
                f = f->next;
                s = s->next;
            }
            else if (f)
            {
                sum = f->data;
                f = f->next;
            }
            else
            {
                sum = s->data;
                s = s->next;
            }
            head = new node(sum);
            head->next = head;
            node *last = head;
            do
            {
                sum = f->data + s->data;
                f = f->next;
                s = s->next;
                t = new node(sum);
                t->next = head;
                last->next = t;
                last = t;
            } while (f != head1 && s != head2);
            if (f != head1)
            {
                do
                {
                    sum = f->data;
                    f = f->next;
                    t = new node(sum);
                    t->next = head;
                    last->next = t;
                    last = t;
                } while (f != head1);
            }
            if (s != head2)
            {
                do
                {
                    sum = s->data;
                    s = s->next;
                    t = new node(sum);
                    t->next = head;
                    last->next = t;
                    last = t;
                } while (s != head2);
            }
        }
    }

    node *getLL()
    {
        return head;
    }
};

int main()
{
    CircularLinkedList ll1;
    CircularLinkedList ll2;
    CircularLinkedList result;

    while (true)
    {
        cout << endl;
        cout << "** Menu **" << endl;
        cout << "1. Create circular linkedlist 1." << endl;
        cout << "2. Create circular linkedlist 2." << endl;
        cout << "3. Add 2 circular linkedlist." << endl;
        cout << "4. Display the resultant linkedlist." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter the choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ll1.create();
            break;
        case 2:
            ll2.create();
            break;
        case 3:
            result.add(ll1.getLL(), ll2.getLL());
            break;
        case 4:
            cout << "Circular linkedlist 1 ." << endl;
            ll1.display();
            cout << "Circular linkedlist 2 ." << endl;
            ll2.display();
            cout << "Resultant Circular linked list : " << endl;
            result.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice . " << endl;
        }
    }

    return 0;
}