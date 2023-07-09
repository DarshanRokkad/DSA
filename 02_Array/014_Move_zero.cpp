// moving the zeros to right side of the array 
#include<iostream> 
using namespace std; 
void movezero(int a[],int n)
{
    int ind = 0 ;
    for(int i = 0 ;i< n ;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[ind]);
            ind++;
        }
    }
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
    
    movezero(a,n);
    cout<<"Array after movement : ";
    for(int i = 0 ;i<n ;i++)
        cout<<a[i]<<" ";        
  
    return 0 ;
}
// input : 7 8 5 0 10 0 5 0 