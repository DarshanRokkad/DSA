// Doubly linked list
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
    struct node *t, *p;
    head = new node;
    head->prev = NULL;
    head->data = a[0];
    head->next = NULL;
    p = head;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        p->next = t;
        t->prev = p;
        t->data = a[i];
        t->next = NULL;
        p = t;
    }
}

int length()
{
    int len = 0;
    struct node *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void display()
{
    struct node *p = head;
    if (p == NULL)
    {
        cout << "No linked list" << endl;
        return;
    }
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void insert(int x, int ind)
{
    if (ind < 0 || ind > length())
    {
        cout << "Index out of range . " << endl;
        return;
    }
    struct node *t, *p;
    if (ind == 0)
    {
        t = new struct node;
        t->prev = NULL;
        t->data = x;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        t = new struct node;
        t->data = x;
        p = head;
        for (int i = 0; i < ind - 1; i++)
        {
            p = p->next;
        }
        // new node links
        t->prev = p;
        t->next = p->next;
        // if new node is not a last node the next node should point on new node
        if (t->next)
        {
            // modification of next node to new node
            // p = t->next ;
            // p->prev = t ;
            p->next->prev = t;
        }
        // modification of previous node to new node
        p->next = t;
    }
}

void delete_node(int pos)
{
    if (pos < 1 || pos > length())
    {
        return;
    }
    struct node *p;
    p = head;
    if (pos == 1)
    {
        head = head->next;
        // if head is not pointing null then
        if (head)
        {
            head->prev = NULL;
        }
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        // if the deleting node is not a last node then
        if (p->next)
        {
            p->next->prev = p;
        }
    }
}

void reverse()
{
    struct node *p = head, *t;
    while (p != NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            head = p;
        }
    }
}

int main()
{
    int arr[] = {2, 3, 5, 7, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    display();
    cout << endl;

    // creating the doubly linked list
    create(arr, size);
    cout << "Creating a doubly linked list " << endl;
    cout << "Doubly linked list : ";
    display();
    cout << "Length of the doubly linked list : " << length() << endl
         << endl;

    // Inserting nodes in the doubly linked list
    cout << "Inserting a doubly linked list " << endl;
    insert(56, 0);
    insert(34, 4);
    insert(1, 8);
    cout << "Doubly linked list : ";
    display();
    cout << "Length of the doubly linked list : " << length() << endl;
    cout << endl;

    // deleting a node in a doubly linked list
    cout << "Deleting a node from a doubly linked list" << endl;
    delete_node(5);
    delete_node(1);
    cout << "Doubly linked list : ";
    display();
    cout << "Length of the doubly linked list : " << length() << endl;
    cout << endl;

    // reversing a doubly linked list
    cout << "Reversing a doubly linked list " << endl
         << endl;
    reverse();
    cout << "Doubly linked list : ";
    display();

    return 0;
}