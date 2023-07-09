// checking whether the linked list is linear or LOOP
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    // here t is to create a node
    // and here last is to traverse through linked list
    struct node *t, *last;
    // creating first node
    head = new node;
    head->data = a[0];
    head->next = NULL;
    // to traverse through linked list we are assigning the first node
    last = head;

    // storing data in the node
    for (int i = 1; i < n; i++)
    {
        // creating new node
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void display(struct node *p)
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

bool isLoop(struct node *f)
{
    struct node *p, *q;
    f = p = q;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    } while (p && q && p != q);
    return (p == q) ? true : false;
}

int main()
{
    struct node *t1, *t2;
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);

    t1 = head->next->next;
    t2 = head->next->next->next->next;
    t2->next = t1;
    
    cout << "Wheather the linked list is has loop or not : " << isLoop(head) << endl;

    return 0;
}