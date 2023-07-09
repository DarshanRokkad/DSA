// Tower of hanai
#include<iostream> 
using namespace std; 

// recursive function
// (number of disks , from , auxillary , to )
void TOH(int n ,int a ,int b ,int c )
{
    if(n>0)
    {
        // Move disks from a to b using c
        TOH(n-1,a,c,b);
        // Move from a to c 
        cout<<a<<" to "<<c<<endl;
        // Move disks from b to c using a 
        TOH(n-1,b,a,c);
    }
}

int main() 
{ 
    TOH(4,1,2,3);
  
    return 0 ;
}