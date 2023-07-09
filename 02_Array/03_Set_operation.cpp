// Set operation on 2 arrays
#include<iostream> 
using namespace std; 
int main() 
{ 
    int arr1[5]={2,6,10,15,25};
    int arr2[5]={3,15,6,7,20};
    int arr3[10];
    int i = 0 , m = 5 ,j = 0 , n = 5 , k = 0;

    // for union of 2 array 
    // while(i<m&&j<n)
    // {
    //     if(arr1[i]<arr2[j])
    //     {
    //         arr3[k++]=arr1[i++];
    //     }
    //     else if(arr1[i]>arr2[j])
    //     {
    //         arr3[k++]=arr2[j++];
    //     }
    //     else
    //     {
    //         arr3[k++]=arr2[j];
    //         i++; j++;
    //     }
    // }
    // for(;i<m;i++)
    // {
    //     arr3[k++]=arr1[i++];
    // }
    // for(;j<n;j++)
    // {
    //     arr3[k++]=arr2[j++];
    // }

    // for intersection of 2 array 
    // for(int i = 0 ;i<m ;i++)
    // {
    //     for(int j = 0 ;j<n;j++)
    //     {
    //         if(arr1[i]==arr2[j])
    //         {
    //             arr3[k++]=arr1[i];
    //             j = n ;
    //         }
    //     }
    // }

    // for difference of to 2 array 
    for(;i<m;i++)
    {
        int flag = 1;
        for(j=0;j<n;j++)
        {
            if(arr1[i]==arr2[j])
            {
                flag = 0 ;
                j = n;
            }
        }
        if(flag)
        {
            arr3[k++]=arr1[i];
        }
    }

    // for printing the resultant array
    for(int p = 0 ;p<k;p++)
    {
        cout<<arr3[p]<<" ";
    }
  
    return 0 ;
}