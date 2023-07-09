// Singly linked list
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

class singlyLinkedlist
{
public:
    node *head;
    singlyLinkedlist()
    {
        head = NULL;
    }
    // This is inserting an element in the linear linked at the end 
    void insert(int x)
    {
        node *temp = new node(x);
        cout << x << " is inserted to linked list." << endl;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        display();
    }
    // Display the linear linked list 
    void display()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty." << endl;
        }
        else
        {
            cout << "Singly linked list." << endl;
            node *p = head;
            while (p)
            {
                cout << p->data;
                p = p->next;
                if (p)
                    cout << " <- ";
            }
            cout << endl<< endl;
        }
    }
    // Reversing the linked list using recursion method
    void rreverse(node *p, node *q)
    {
        if (p)
        {
            rreverse(p->next, p);
            p->next = q;
        }
        else
        {
            head = q;
        }
    }
    // Reversing the linked list using 3 pointers method 
    void reverse()
    {
        node *f , *s  , *t ;
        f = head ;
        s = t = NULL ;
        while(f)
        {
            t = s ; 
            s = f ;
            f = f->next;
            s->next = t ;
        } 
        head = s ;
        cout<<"Linked list is reversed ."<<endl;
        display();
    }
};

int main()
{
    int a[] = {2, 4, 3, 7, 5};
    int size = sizeof(a) / sizeof(a[0]);
    singlyLinkedlist s;
    for (int i = 0; i < size; i++)
    {
        s.insert(a[i]);
    }
    s.rreverse(s.head, NULL);
    cout<<"Linked list is reversed ."<<endl;
    s.display();
    s.reverse();

    return 0;
}