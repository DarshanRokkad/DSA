// Circular linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *head;

void create(int a[], int n)
{
    struct node *last, *t;
    head = new struct node;
    head->data = a[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new struct node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display()
{
    struct node *p = head;
    do
    {
        cout << p->data << ' ';
        p = p->next;
    } while (p != head);
    cout << endl;
}

int length()
{
    int len = 0 ;
    if(head==NULL)
    {
        return 0 ;
    }
    else
    {
        struct node *p = head;
        // do
        // {
        //     len++;
        //     p=p->next;
        // } while (p!=head);     
        while(p->next!=head)
        {
            len++;
            p=p->next;
        }   
        len++;
    }
    return len;
}

void rdisplay(struct node *p)
{
    static int flag = 0;
    if (head != p || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        rdisplay(p->next);
    }
}

void insert(int pos, int x)
{
    struct node *t, *p;
    t = new node;
    t->data = x;
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int delete_node(int pos)
{
    int x=-1;
    if(pos<1||pos>length())
    {
        return x;
    }
    struct node *p, *q;
    if (pos == 1)
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        p = head ;
        for(int i = 0 ;i<pos-2 ;i++)
        {
            p = p->next;
        }
        q = p->next ;
        p->next = q->next ;
        x = q->data;
        delete q ;
    }
    return x ;
}

int main()
{
    int a[] = {3, 5, 7, 2, 9};
    int size = sizeof(a) / sizeof(a[0]);

    create(a, size);
    cout << "Displaying circular linked list : ";
    display();
    rdisplay(head);
    cout << endl;

    insert(0, 78);
    insert(3, 97);
    display();

    cout<<delete_node(5)<<" is delted form the linked list"<<endl;
    cout<<delete_node(1)<<" is delted form the linked list"<<endl;
    display();
    cout<<"Length of the linked list is "<<length()<<endl;

    return 0;
}