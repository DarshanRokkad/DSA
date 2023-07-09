// Finding second largest element of the array 
#include<iostream> 
using namespace std;
int Second(int a [] , int n)
{
    int seclar = -1 , lar = 0 ;
    for(int i  = 1 ;i<n ;i++)
    {
        if(a[i]>a[lar])
        {
            seclar = lar ;
            lar = i ; 
        }
        else if (a[i]!=a[lar])
        {
            if(seclar==-1||a[seclar]<a[i])
            {
                seclar = i ;
            }
        }
    }
    return seclar ;
} 
int main() 
{ 
    int n ;
    cout<<"Enter nubmer of elements of the array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ;i<n ;i++)
        cin>>a[i];

    // solution 
    cout<<"Second largest is : "<<Second(a,n);
  
    return 0 ;
}
// input 
// 5 10 5 8 20 3
// 5 20 10 20 80 12
// 3 10 10 10