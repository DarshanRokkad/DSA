// Calculating the average of n numbers using the variable arguements
#include<iostream> 
using namespace std; 
double average(int n, ...)
{
    va_list args ;
    double sum = 0 ;

    _crt_va_start(args, n);
    for(int i = 0 ;i<n ;i++)
        sum+=_crt_va_arg(args,double);
    _crt_va_end(args);

    return sum/n;
}

int main() 
{ 
    cout<<average(4,5,2);
  
    return 0 ;
}