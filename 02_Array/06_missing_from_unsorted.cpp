// Missing of multiple elements in multiple place in unsorted array
#include<iostream> 
using namespace std; 
int main() 
{ 
    int a[10]={3,7,4,9,12,6,1,11,2,10};
    int l = 1 , maxele = 12 , n = 10 ;
    int H[maxele]={0}; // implementation of hash table
    for(int i = 0 ;i<n;i++)
    {
        H[a[i]]++;
    }
    for(int i = l ; i<=maxele ;i++)
    {
        if(H[i]==0)
        {
            cout<<i<<" ";
        }
    }
  
    return 0 ;
}