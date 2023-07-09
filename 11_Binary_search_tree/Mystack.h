// stack with doubly linked list
template <class t>
class dnode
{
public:
    t data;
    dnode *prev;
    dnode *next;
    dnode(t x)
    {
        data = x;
        prev = next = NULL;
    }
};
template <class t>
class Mystack
{
private:
    dnode<t> *head;
    dnode<t> *last;

public:
    Mystack()
    {
        last = head = NULL;
    }
    void push(t p)
    {
        dnode<t> *temp = new dnode<t>(p);
        if (head == NULL)
        {
            head = last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
            last = last->next;
        }
    }
    t top()
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            return (last->data);
        }
    }
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        if (head == last)
        {
            delete head;
            head = last = NULL;
        }
        else
        {
            last = last->prev;
            delete last->next;
            last->next = NULL;
        }
    }
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
};