// INdirect recursion
#include<iostream> 
using namespace std; 
void funb(int);
void funa(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funb(n-1);
    }
}
void funb(int n )
{
    if(n>0)
    {
        cout<<n<<" ";
        funa(n/2);
    }
}
int main() 
{ 
    funa(20);  
  
    return 0 ;
}