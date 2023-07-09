// Finding the peak element in the array 
#include<iostream> 
using namespace std; 

int PeakElement(int a[],int low , int high,int n)
{
    // the below code will give 20 as the peak element this is to be used in the case of searching of peak element in left half of the array 
    int mid = (low+high)/2;
    if((mid==0||a[mid-1]<a[mid])&&(mid==n-1||a[mid+1]<a[mid]))
    {
        return a[mid];
    }
    else if(mid>0&&a[mid-1]>a[mid])
    {
        return PeakElement(a,low,mid-1,n);
    }
    else 
    {
        return PeakElement(a,mid+1,high,n);
    }

    // the below code will give 90 as the peak element this is to be used in the case of searching of peak element in right half of the array 
    // else if(mid<n-1&&a[mid+1]>a[mid])
    // {
    //     return PeakElement(a,mid+1,high,n);
    // }
    // else 
    // {
    //     return PeakElement(a,low,mid-1,n);
    // }
}

int main() 
{ 
    int n = 7;
    int a[n]={10,20,15,2,23,90,67};
    // here the peak element is 20 or 90
    int answer = PeakElement(a,0,n-1,n);
    for(int x : a)
    {
        cout<<x<<" ";
    }cout<<endl;
    cout<<"The peak element of the array is "<<answer<<endl;
  
    return 0 ;
}