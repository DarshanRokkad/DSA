// cancatination of 2 linked list
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
struct node *cancati(struct node *first, struct node *second)
{
    struct node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
    return first;
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
    int a[] = {2, 5, 7, 1, 6};
    int b[] = {1, 3, 9, 12, 56};
    int n = sizeof(a) / sizeof(a[0]);

    struct node *first = create(a, n);
    n = sizeof(b) / sizeof(b[0]);
    struct node *second = create(b, n);

    struct node *ans = cancati(first, second);

    display(ans);

    return 0;
}