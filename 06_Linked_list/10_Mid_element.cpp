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
private:
    node *head;

public:
    singlyLinkedlist()
    {
        head = NULL;
    }
    void insert(int x)
    {
        node *temp = new node(x);
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
            dispaly();
        }
    }
    void dispaly()
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
            cout << endl
                 << endl;
        }
    }
    void midElement()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty." << endl;
        }
        else
        {
            node *p = head;
            node *q = head;
            while (q && q->next)
            {
                p = p->next ;
                q = q->next ;
                q = q->next ;
            }
            cout<<"Middle element is "<<p->data<<endl;
        }
    }
};

int main()
{
    int a[] = {2, 4, 3, 7, 5 ,6};
    int size = sizeof(a) / sizeof(a[0]);
    singlyLinkedlist s;
    for (int i = 0; i < size; i++)
    {
        s.insert(a[i]);
    }
    s.midElement();
    

    return 0;
}