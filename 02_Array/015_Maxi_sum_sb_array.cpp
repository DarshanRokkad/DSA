// Maximum sum of the sub array
#include <iostream>
using namespace std;

int maxsum(int a[], int n)
{
    int sum = 0;
    int so_far_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (so_far_max < sum && sum> 0)
        {
            so_far_max = sum;
        }
        else if (sum < 0)
        {
            sum = 0 ;
        }
    }
    return so_far_max;
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
    
    // output 
    int ans = maxsum(a, n);
    cout << ans;

    return 0;
}
// input : 6 -3 4 -1 -2 1 5