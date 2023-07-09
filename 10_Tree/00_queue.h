// This queue is used to store the address of the node of the binary tree
template <class t>
class nodeq
{
public:
    t data;
    nodeq *next;
    nodeq(t x)
    {
        data = x;
        next = NULL;
    }
};

template <class T>
class MyQueue
{
private:
    int size;
    nodeq<T> *head = NULL;
    nodeq<T> *last = NULL;

public:
    MyQueue()
    {
        size = 0;
    }
    void enque(T x)
    {
        nodeq<T> *temp = new nodeq<T>(x);
        if (size == 0)
        {
            last = head = temp;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
        size++;
    }

    T deque()
    {
        if (size == 0)
        {
            return 0;
        }
        else
        {
            T data = head->data;

            nodeq<T> *temp = head;
            head = head->next;
            delete temp;
            if (!head)
                last = NULL;
            size--;
            return data;
        }
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};