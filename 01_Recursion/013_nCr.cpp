// finding  nCr 
#include<iostream> 
using namespace std;

// Recursive Method 1 
int C(int n ,int r)
{
    if(r==0||r==n)
    {
        return 1;
    }
    return C(n-1,r-1)+C(n-1,r);
}

// Method 2
// int fact(int n)
// {
//     int f = 1 , i =1 ;
//     for(i = 1 ;i<=n;i++)
//     {
//         f=f*i;
//     }
//     return f ;
// }
// int C(int n , int r)
// {
//     int a , b ,c ;
//     a = fact(n);
//     b = fact(n-r);
//     c = fact(r);
//     return a/(b*c);
// }

int main() 
{ 
    cout<<C(4,2)<<endl;
  
    return 0 ;
}