// Creating Linked list using create function
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p, int ele, int ind)
{
    if (ind < 0 || ind > count(head))
    {
        return;
    }
    struct Node *t;
    // inserting before first node or inserting at index 0
    if (ind == 0)
    {
        t = new struct Node;
        t->data = ele;
        t->next = head;
        head = t;
    }
    // inserting at a cerian index index
    else if (ind > 0)
    {
        for (int i = 0; i < (ind - 1) && ind; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = new struct Node;
            t->data = ele;
            t->next = p->next;
            p->next = t;
        }
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        // printing the data
        cout << p->data << " ";
        // moving to next node
        p = p->next;
    }
    cout << endl;
}

int main()
{

    insert(head, 10, 0);
    insert(head, 5, 1);
    insert(head, 8, 2);

    cout << "Linked list 1 : ";
    display(head);

    return 0;
}