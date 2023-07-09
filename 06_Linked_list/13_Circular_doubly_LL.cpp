// Circular doubly linked list
#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class DoublyCircluarLL
{
private:
    node *head;

public:

    DoublyCircluarLL()
    {
        head = NULL;
    }

    // insert the node before the head 
    void insertBegin(int x)
    {
        cout << x << " is inserted at the begining." << endl;
        node *temp = new node(x);
        if (head == NULL)
        {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else
        {
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
        }
        display();
    }

    // insert the node at the end 
    void insertEnd(int x)
    {
        cout << x << " is inserted at the end." << endl;
        node *temp = new node(x);
        if (head == NULL)
        {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else
        {
            temp->prev = head->prev;
            temp->next = head;
            head->prev->next = temp;
            head->prev = temp;
        }
        display();
    }

    // delete the first node 
    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "Linked list empty." << endl;
        }
        else if (head->next == head)
        {
            cout << "Deleted first node." << endl;
            delete head;
            head = NULL;
        }
        else
        {
            cout << "Deleted first node." << endl;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            node *first = head;
            head = head->next;
            delete first;
        }
        display();
    }

    // delete the last node
    void deleteLast()
    {
        if (head == NULL)
        {
            cout << "Linked list empty." << endl;
        }
        else if (head->next == head)
        {
            cout << "Deleted last node." << endl;
            delete head;
            head = NULL;
        }
        else
        {
            cout << "Deleted last node." << endl;
            node *last = head->prev;
            head->prev->prev->next = head ;
            head->prev = head->prev->prev ; 
            delete last;
        }
        display();
    }

    // display the node 
    void display()
    {
        if (head == NULL)
        {
            cout << "Circular doubly linked list empty." << endl;
        }
        else
        {
            cout << "Circular doubly linked list : ";
            node *p = head;
            do
            {
                cout << p->data << " ";
                p = p->next;
            } while (p != head);
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    cout<<"*** Circluary doubly linked list ***"<<endl;
    DoublyCircluarLL dcl;
    dcl.insertBegin(3);
    dcl.insertEnd(6);
    dcl.insertBegin(4);
    dcl.insertEnd(2);
    dcl.insertEnd(8);
    dcl.deleteFirst();
    // dcl.deleteFirst();
    dcl.deleteLast();
    dcl.insertBegin(34);
    dcl.insertEnd(12);

    return 0;
}