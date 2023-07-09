// Pair with sum k
#include<iostream> 
using namespace std; 
int main() 
{ 
    int a[10]={6,3,8,10,16,7,5,2,9,14};
    int k = 10 ;
    int n = 10 ;
    for(int i = 0 ;i<n;i++)
    {
        for(int j = i+1 ;j<n ;j++)
        {
            if(a[i]+a[j]==k)
            {
                cout<<a[i]<<" + "<<a[j]<<" = "<<k<<endl;
            }
        }
    }
  
    return 0 ;
}