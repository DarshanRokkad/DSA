// Circular linked list
#include <iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    struct node *p, *t;
    t = new node();
    t->data = a[0];
    // both the previous and next should point on the same node in first
    t->next = t;
    t->prev = t;
    head = p = t;
    for (int i = 1; i < n; i++)
    {
        t = new node();
        t->data = a[i];
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
        p = p->next;
    }
}

int length()
{
    struct node *p = head;
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void display()
{
    if (head == NULL)
    {
        cout << "Linked list not created " << endl
             << endl;
        return;
    }
    struct node *p = head;
    cout << "Circularly doubly linked list : ";
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
    cout << "Length of circularly doubly linked list : " << length();
    cout << endl
         << endl;
}

void insert(int x, int pos)
{
    if (pos < 0 && pos > length())
    {
        return;
    }
    struct node *p, *t;
    // inserting before first node and inserting after last node is same
    if (pos == 0)
    {
        if (head)
        {
            t = new node();
            t->data = x;
            p = head->prev;
            // t->next = head ;
            // t->prev = head->prev ;
            // p->next = t ;
            // head->prev = t;
            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
            head = t;
        }
        else
        {
            head = new node();
            head->data = x;
            head->prev = head;
            head->next = head;
        }
    }
    // inserting element at particular position
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new node();
        t->data = x;
        t->prev = p;
        t->next = p->next;
        // p->next = t ;
        // t->next->prev = t;
        p->next->prev = t;
        p->next = t;
    }
}

void delete_node(int pos)
{
    if (pos < 1 || pos > length())
    {
        cout << "out of range " << endl;
        return;
    }
    struct node *p ;
    if (pos == 1)
    {
        p = head->prev;
        p->next = head->next;
        head->next->prev = p;
        delete head;
        head = p->next;
    }
    else
    {
        p = head ;
        for(int i = 0 ;i<pos-1 ;i++)
        {
            p=p->next ;
        }
        p->prev->next = p->next ;
        p->next->prev = p->prev ;
        delete p ;
    }
}

int main()
{
    int arr[] = {2, 3, 5, 7, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    display();

    // creating the doubly circular linked list
    cout << "...Creating circularly doubly linked list.. " << endl;
    create(arr, size);
    display();

    // inserting the nodes
    cout << "...Inserting nodes... " << endl;
    insert(45, 0);
    display();
    insert(1, 5);
    display();
    insert(92, 8);
    display();

    // deleting nodes 
    cout<<"...Deleting nodes... "<<endl;
    delete_node(1);
    display();
    delete_node(length());
    display();
    delete_node(4);
    display();
    
    return 0;
}