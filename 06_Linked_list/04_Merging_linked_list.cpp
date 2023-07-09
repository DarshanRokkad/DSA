// merging of 2 linked list
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *create(int a[], int n)
{
    struct node *p = new struct node;
    p->data = a[0];
    p->next = NULL;
    struct node *head = p;
    for (int i = 1; i < n; i++)
    {
        struct node *t = new struct node;
        t->data = a[i];
        t->next = NULL;
        p->next = t;
        p = p->next;
    }
    return head;
}

// this is cancatination of first linked list with second
struct node *merging(struct node *first, struct node *second)
{
    struct node *result_head;
    struct node *last;
    // to point the result linked list on the first node
    if (first->data < second->data)
    {
        last = result_head = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        last = result_head = second;
        second = second->next;
        last->next = NULL;
    }
    // to link the remaining linked list
    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = last->next;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = last->next;
            second = second->next;
            last->next = NULL;
        }
    }
    // if(first!=NULL)
    if (first)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
    return result_head;
}

void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 5, 6, 10};
    int b[] = {3, 9, 12, 56};
    int n = sizeof(a) / sizeof(a[0]);

    struct node *first = create(a, n);
    n = sizeof(b) / sizeof(b[0]);
    struct node *second = create(b, n);

    cout << "First linked list : ";
    display(first);
    cout << "Second linked list : ";
    display(second);

    struct node *ans = merging(first, second);

    cout << "Merged linked list : ";
    display(ans);

    return 0;
}