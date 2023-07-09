// Pair with sum k in sorted array
#include<iostream> 
using namespace std; 
int main() 
{ 
    int a[10]={1,3,4,5,6,8,9,10,12,14};
    int s = 10 ;
    int i = 0 , n = 10;
    int j = n - 1 ;
    while(i<j)
    {
        if(a[i]+a[j]>s)
        {
            j--;
        }
        else if(a[i]+a[j]<s)
        {
            i++;
        }
        else
        {
            cout<<a[i]<<" + "<<a[j]<<" = "<<s<<endl;
            i++;
            j--;
        }
    }
  
    return 0 ;
}