#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *first = head, *laste = NULL;
// it is now just like a pointer holding nothing
// both NULL and NULL works in c++

void create(int a[], int n)
{
    // here t is to create a node
    // and here last is to traverse through linked list
    struct Node *t, *last;
    // creating first node
    head = new Node;
    head->data = a[0];
    head->next = NULL;
    // to traverse through linked list we are assigning the first node
    last = head;

    // storing data in the node
    for (int i = 1; i < n; i++)
    {
        // creating new node
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// display the linked list
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

// displaying the linked list in the reverse order - recurively
void reverse_display(struct Node *r)
{
    if (r == NULL)
    {
        return;
    }
    reverse_display(r->next);
    cout << r->data << " ";
}

// counting number of nodes
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

// finding sum of all the elements in the nodes
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// finding the maximum elements the linked list
int max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// finding the minmum element in the linked list
int min(struct Node *p)
{
    int min = INT_MAX;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

// linear search of a key and returning of the address of the element i.e returning the address of the paticular node
struct Node *linear_search(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            // returning address of the node
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
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
        p = head;
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

void insertLast(struct Node *p, int e)
{
    struct Node *t = new struct Node;
    t->data = e;
    t->next = NULL;
    if (p == NULL)
    {
        first = laste = t;
    }
    else
    {
        laste->next = t;
        laste = t;
    }
}

void find_last()
{
    laste = head;
    while (laste != NULL)
    {
        if (laste->next == NULL)
        {
            break;
        }
        laste = laste->next;
    }
}

void sort_insert(int x)
{
    struct Node *p = head;
    struct Node *q = NULL;
    struct Node *t = new struct Node;
    t->data = x;
    t->next = NULL;
    // head there is no node
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (p && (x > p->data))
        {
            q = p;
            p = p->next;
        }
        // if first node data is the less one then we should insert the new data before first node
        // or the below can also be written as if(p==head)
        if (q == NULL)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete_node(int pos)
{
    struct Node *p, *q;
    int x = -1;
    if (pos > 0 || pos < count(head))
    {
        // deleting from first position
        if (pos == 1)
        {
            p = head;
            head = head->next;
            x = p->data;
            delete p;
        }
        // deleting from the given position
        else
        {
            p = head;
            q = NULL;
            // moving pointer to the position
            for (int i = 1; i < pos; i++)
            {
                q = p;
                p = p->next;
            }
            // checking if the deleting position in valid (or) not
            if (p)
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }
    return -1;
}

bool isSorted()
{
    int x = -65536;
    struct Node *p = head;
    if (count(head) <= 1)
    {
        return 1;
    }
    while (p)
    {
        if (x > p->data)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void remove_duplicates()
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p)
    {
        if (p->data != q->data)
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}

void reverse()
{
    struct Node *p, *q, *r;
    p = head;
    q = NULL;
    r = NULL;
    while(p!=NULL)
    {
        // sliding pointers
        r = q ;
        q = p ;
        p = p->next;
        // pointing to previous node 
        q->next = r;
    }
    head = q ;
}

int mid_element()
{
    struct Node *p , *q ;
    p = q = head ;
    while(q)
    {
        q=q->next ;
        if(q)
        {
            q=q->next ;
        }
        if(q)
        {
            p=p->next ;
        }
    } 
    return (p->data);
}

int main()
{
    int a[] = {3, 5, 7, 10, 56};
    int size = sizeof(a) / sizeof(a[0]);

    create(a, size);

    // display
    cout << "Elements of the linked list : ";
    display(head);

    // reverse display
    cout << "Elements of the linked list in reverse order : ";
    reverse_display(head);
    cout << endl;

    // no of elements
    cout << "Number of elements in linked list : " << count(head) << endl;

    // sum of elements
    cout << "Sum of elements of the array : " << sum(head) << endl;

    // max element in linked list
    cout << "Maximum element in the linked list is " << max(head) << endl;

    // min element in linked list
    cout << "Minmum element in the linked list is " << min(head) << endl;

    // linear searching
    int key = 7;
    // answer node pointing to the address of the key
    // answer data will be the key answer address will be the key address
    struct Node *ans = linear_search(head, key);
    key = 3;
    ans = linear_search(head, key);
    if (ans == NULL)
    {
        cout << key << " is not present in the linked list" << endl;
    }
    else
    {
        cout << (ans->data) << " is present at address " << ans << " in a linked list" << endl;
    }
    cout << "After this the key will be the first node : ";
    display(head);

    // insertion of element at certian index
    int ele = 9, ind = 3;
    insert(head, ele, ind);
    cout << "Linked list after insertion at 3rd index : ";
    display(head);

    // insertion at last of the linked list
    find_last();
    insertLast(head, 89);
    cout << "Display : ";
    display(head);

    // insertion in sorted linked list
    cout << "Inserted 1 and 60 and 95 in sorted linked list : ";
    sort_insert(1);
    sort_insert(60);
    sort_insert(95);
    display(head);

    // deleting a node
    cout << delete_node(1) << " is deleted from the linked list" << endl;
    cout << "Deleted element from the position 1 : ";
    display(head);

    cout << delete_node(4) << " is deleted from the linked list" << endl;
    cout << "Deleted element from the position 4 : ";
    display(head);
    cout << delete_node(2) << " is deleted from the linked list" << endl;
    cout << "Deleted element from the position 7 : ";
    display(head);

    // checking whether linked list is sorted or not
    cout << "Is array is sorted : " << isSorted() << endl;

    // removing the duplicates 
    insert(head, 95, 7);
    cout << "Before removing : ";
    display(head);
    remove_duplicates();
    cout << "removed duplicates : ";
    display(head);

    // reversing a linked list  
    reverse();
    cout<<"After reversing a linked list : ";
    display(head);

    // mid element of the linked list 
    cout<<"Mid element of the linked list : "<<mid_element()<<endl;
    cout<<"linked list after inserting 30 : ";
    insert(head , 30,3);
    display(head);
    cout<<"Mid element of the linked list : "<<mid_element()<<endl;

    return 0;
}