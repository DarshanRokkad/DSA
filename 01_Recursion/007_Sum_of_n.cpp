// Sum of first n natural numbers
#include<iostream> 
using namespace std; 

// recursive method 1
int sum(int n)
{
    if(n==0)
    {
        return 0 ;
    }
    else
    {
        return n+sum(n-1);
    }
}

// method 2 
// int sum(int n )
// {
//     return (n*(n+1)/2);
// } 

// method 3
// int sum(int n )
// {
//     int s = 0 ;
//     for(int i = 1 ;i<=n;i++)
//     {
//         s+=i;
//     }
//     return s;
// }

int main() 
{ 
    cout<<sum(5);
  
    return 0 ;
}