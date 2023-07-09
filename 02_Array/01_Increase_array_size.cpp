// increasing size of array at runtime
#include<iostream>
using namespace std;
int main()
{
    int old ;
    cout<<"Enter the number of elements of the array : ";
    cin>>old;
    int *p ;
    p = new int[old];
    cout<<"Size of the old array is : "<<old<<endl;

    // new array 
    int newsize;
    cout<<"Enter the number of elements of the new array : ";
    cin>>newsize;
    int *q ;
    q = new int[newsize];
    cout<<"Size of the new array is : "<<newsize<<endl;

    // delete old array
    delete []p;
    // assign new array 
    p = q ;
    // new pointer is 0
    q = NULL;
    // deleting the old pointer new array also 
    p = NULL;

    return 0 ;
}