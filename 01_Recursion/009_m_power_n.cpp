// m power n
#include<iostream> 
using namespace std; 

// Recursion method 1 
// int power(int m , int n )
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     else
//     {
//         return m*power(m,n-1);
//     }
// }

// Recursion method 2
int power(int m , int n )
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        return power((m*m),n/2);
    }
    else
    {
        return m*power((m*m),(n-1)/2);
    }
}
int main() 
{ 
    cout<<power(2,4);
  
    return 0 ;
}