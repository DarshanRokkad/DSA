// Factorial of a number
#include<iostream> 
using namespace std; 

// using recursion method 1 
int fact(int n )
{
    if(n==0)
    {
        return 1 ;
    }
    else
    {
        return n*fact(n-1);
    }
}

// method 2 
// int fact(int n)
// {
//     int f = 1 , i =1 ;
//     for(i = 1 ;i<=n;i++)
//     {
//         f=f*i;
//     }
//     return f ;
// }

int main() 
{ 
    cout<<fact(5)<<endl;
    cout<<fact(0)<<endl;
  
    return 0 ;
}