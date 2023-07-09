// jagged array  
#include<iostream> 
using namespace std; 
int main() 
{ 
    int r1[]={5,63,34};
    int r2[]={54};
    // this jagged array pointer hold the base address of the 2 array 
    int *jagged[2]={r1,r2};
    int size[]={3,1};
    
    cout<<"Jagged array is : "<<endl; 
    for(int i = 0 ;i<2 ;i++)
    {
        // this pointer holds the address of the base address of the row array 
        int *ptr = jagged[i];
        for(int j = 0 ;j<size[i];j++)
        {
            cout<<*ptr<<" ";
            ptr++;
        }cout<<endl;
    }
  
    return 0 ;
}