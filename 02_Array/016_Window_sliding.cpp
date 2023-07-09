// Window sliding 
#include<iostream> 
using namespace std; 

int Windowsliding(int a[],int n ,int k)
{
    if(n<k)
    {
        return -1 ;
    }
    int max_sum = 0 ;
    for(int i = 0 ;i<k ;i++)
        max_sum+=a[i];
    // sum of first window 
    int window_sum = max_sum ;
    for(int i = k ;i< n ;i++)
    {
        // first window - first element + now element
        window_sum+=a[i]-a[i-k];
        max_sum=max(window_sum,max_sum);
    }

    return max_sum ;
}

int main() 
{ 
    int n;
    cout << "Enter nubmer of elements of the array : ";
    cin >> n;
    int a[n];
    cout << "Enter the elements in array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];    
    int k ;
    cout<<"Enter the value of k : ";
    cin>>k;

    // answer
    int ans = Windowsliding(a,n,k);
    cout<<ans;
  
    return 0 ;
}
// input :
// 4  100 200 300 400   2
// 9  1 4 2 10 23 3 1 0 20   4 