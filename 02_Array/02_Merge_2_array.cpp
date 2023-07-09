// Merging two array
#include <iostream>
using namespace std;
int main()
{
    int a[5]={3,8,16,20,25};
    int b[5]={4,10,12,22,23};
    int c[10]={0};
    int i = 0 , j = 0 , k = 0;
    int m = 5 , n = 5 ;

    // sir logic
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++)
    {
        c[k++]=a[i++];
    }
    for(;j<n;j++)
    {
        c[k++]=b[j++];
    }

    // My logic
    // for( k = 0 ;k<(m+n);k++)
    // {
    //     if(a[i]<b[j]&&i<m&&j<n)
    //     {
    //         c[k]=a[i++];
    //     }
    //     else if(a[i]>b[j]&&i<m&&j<n)
    //     {
    //         c[k]=b[j++];
    //     }
    //     else if(i<m)
    //     {
    //         c[k]=a[i++];
    //     }
    //     else
    //     {
    //         c[k]=a[j++];
    //     }
    // }
    for(int p = 0 ;p<10;p++)
    {
        cout<<c[p]<<" ";
    }

    return 0;
}