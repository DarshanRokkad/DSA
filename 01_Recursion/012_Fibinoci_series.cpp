// Fibinoci series
#include<iostream> 
using namespace std; 
// Memorization 
int F[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1};

int fib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
        {
            F[n-2]=fib(n-2);
        }
        if(F[n-1]==-1)
        {
            F[n-1]=fib(n-1);
        }
        return F[n-2]+F[n-1];
    }
}

// iterative method 2
// int fib(int n)
// {
//     int s = 0 , t0 = 0 , t1 = 1 ;
//     for(int i = 2 ;i<=n ;i++)
//     {
//         s=t0 + t1 ;
//         t0 = t1 ;
//         t1 = s ;
//     }
//     return s;
// }

int main() 
{ 
    int i = 6;
    cout<<fib(i);
  
    return 0 ;
}