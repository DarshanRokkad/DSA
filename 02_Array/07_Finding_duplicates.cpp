// Finding the duplicates of the sorted array
#include<iostream> 
using namespace std; 
int main() 
{ 
    int a[10]={3,6,8,8,10,12,15,15,15,20};
    int n =10 ;
    int lastduplicate = 0 ;
    for(int i = 0 ;i<n-1 ;i++)
    {
        if(a[i]==a[i+1]&&a[i]!=lastduplicate)
        {
            cout<<a[i]<<" ";
            lastduplicate = a[i];
        }
    }
  
    return 0 ;
}