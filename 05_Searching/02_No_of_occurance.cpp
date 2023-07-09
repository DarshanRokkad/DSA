// Number of a given number in the sorted array 
#include<iostream> 
using namespace std;

// find the first occurence of a element 
int first_index(int a[],int l , int h , int x , int n)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if((a[mid]==x)&&(mid==0||x>a[mid-1]))
        {
            return mid ;
        }
        else if(x>a[mid])
        {
            return first_index(a,(mid+1),h,x,n);
        }
        else
        {
            return first_index(a,l,(mid-1),x,n);
        }
    }
    return -1;
}

// find the last occurence of a element 
int last_index(int a[],int l , int h , int x , int n)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if((a[mid]==x)&&(mid==n-1||x<a[mid+1]))
        {
            return mid ;
        }
        else if(x<a[mid])
        {
            return last_index(a,l,(mid-1),x,n);
        }
        else
        {
            return last_index(a,(mid+1),h,x,n);
        }
    }
    return -1;
}

int count(int a[],int n , int x)
{
    int i = first_index(a,0,n-1,x,n);
    int j = last_index(a,0,n-1,x,n);
    int occ = (j-i)+1;
    return occ;
}

int main() 
{ 
    int arr[]={1,1,2,2,2,2,3,3};
    int key = 2 ;
    int n = 8 ;
    int answer = count(arr,n,key);
    cout<<key<<" is present "<<answer<<" times in the array "<<endl;
  
    return 0 ;
}