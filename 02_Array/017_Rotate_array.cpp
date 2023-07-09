// roatate an array by D times
#include<iostream> 
using namespace std; 
void rotateArr(int arr[], int d, int n){
        // code here
        int tem[d];
        for(int i = 0 ;i<d;i++)
            tem[i]=arr[i];
        for(int i = d;i<n;i++)
            arr[i-d]=arr[i];
        for(int i = 0;i<d ;i++)
            arr[n-d+i]=tem[i];
    }
int main() 
{ 
    int a[]={2,4,6,8,10,12,14,16,18,20};
    int d = 3 ;
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0 ;i<n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    rotateArr(a,d,n);
    for(int i = 0 ;i<n ;i++)
    {
        cout<<a[i]<<" ";
    }
  
    return 0 ;
}