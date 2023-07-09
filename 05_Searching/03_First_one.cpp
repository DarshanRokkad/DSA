// Finding the first one in the sorted array of 0's and 1's
#include<iostream> 
using namespace std; 

int firstone(int a[],int low ,int high)
{
    int mid=(low+high)/2;
    if(a[low]==1)
    {
        return low ;
    }
    else if(a[mid]==1&&a[mid-1]==0)
    {
        return mid;
    }
    // then if below condition then we have to search we have to search in left half array 
    else if(a[mid]==1)
    {
        firstone(a,low,mid-1);
    }
    else
    {
        firstone(a,mid+1,high);
    }
}

int main() 
{ 
    int a[]={1,1,1,1,1,1,1,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"The first 1 index in the sorted 1 and 0 array is "<<firstone(a,0,n-1);
  
    return 0 ;
}