// Remove duplicate from an array 
#include<iostream> 
using namespace std; 
int remdup(int a[],int n)
{
    int ind = 1 ;
    for(int i = 1 ;i<n ;i++)
    {
        if(a[i]!=a[ind-1])
        {
            a[ind++]=a[i];
        }
    }
    return ind;
}
int main() 
{ 
    int n ;
    cout<<"Enter nubmer of elements of the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements in sorted order array : ";
    for(int i = 0 ;i<n ;i++)
        cin>>a[i];

    n = remdup(a,n);
    cout<<"Result array : ";
    for(int i = 0 ;i<n ;i++)
        cout<<a[i]<<" ";
  
    return 0 ;
}
// input : 6 10 20 20 30 30 30