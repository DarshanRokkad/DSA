// Number of duplicate
#include<iostream> 
using namespace std; 
int main() 
{ 
    int a[10]={3,6,8,8,10,12,15,15,15,20};
    int n = 10 ;
    for(int i = 0 ;i<n-1 ;i++)
    {
        if(a[i]==a[i+1])
        {
            int j = i+1;
            while(a[i]==a[j])
            {
                j++;
            }
            cout<<a[i]<<" => "<<j-i<<endl;
            i=j-1;
        }
    }
  
    return 0 ;
}