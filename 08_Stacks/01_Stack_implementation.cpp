// Implementation of stack using struct and array
#include<iostream> 
using namespace std;
struct MyStack
{
    int capacity ;
    int top ;
    int *arr ;

    // constructor to intialise the stack 
    MyStack(int n)
    {
        capacity = n ;
        top = -1 ;
        arr = new int[n];
    }

    // To push the element into the stack
    void push(int x)
    {
        if(top==(capacity-1))
        {
            cout<<"Overflow condition."<<endl;
        }
        else
        {
            arr[++top] =  x;
        }
    }

    // To pop the element from the stack and returns the poped value 
    int pop()
    {
        if(top==-1)
        {
            cout<<"Underflow condition."<<endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    // returns the top most element inside the stack
    int peek()
    {
        return arr[top];
    }

    // returns the size of the stack
    int size()
    {
        return (top+1);
    }

    // returns true if stack is empty
    bool isEmpty()
    {
        return (top==-1);
    }

} ;
int main() 
{ 
    MyStack s(4);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(6);
    s.push(9);
    cout<<"Peek element : "<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Size of the stack : "<<s.size()<<endl;
    cout<<"Is empty : "<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Is empty : "<<s.isEmpty()<<endl;
  
    return 0 ;
}