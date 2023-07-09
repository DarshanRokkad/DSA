// Linear search 
#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std; 
class Searching
{
    private :
    vector<int> v;
    public:
    Searching(vector<int>vi)
    {
        v = vi ;
    }

    // Linear search 
    int lsearch(int element)
    {
        // vector<int>::iterator it = v.begin();
        // for(;it!=v.end();it++)
        // {
        //     if(*it==element)
        //     {
        //         int index = it-v.begin() ;
        //         return index;
        //     }
        // }
        for(int i = 0 ;i<v.size();i++)
        {
            if(element==v[i])
            {
                return i ;
            }
        }
        return -1;
    }

    // Binary search 
    int bsearch(int element)
    {
        int low =  0 ;
        int high = v.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(element==v[mid])
            {
                return mid;
            }
            else if(element<v[mid])
            {
                high=mid-1;
            }
            else
            {
                low = mid + 1 ;
            }
        }
        return -1;
    }
    // inbuilt functions 
    bool in_bsearch(int element)
    {
        // include the algorithm header file
        return binary_search(v.begin(),v.end(),element);
    }

    // inbuilt function for upper bound returns the index of the upper bound element 
    int ubound_index(int element)
    {
        vector<int>::iterator up= upper_bound(v.begin(),v.end(),element);
        return (up-v.begin());
    }
    // inbuilt function for upper bound returns the upper bound element 
    int ubound_ele(int element)
    {
        vector<int>::iterator up= upper_bound(v.begin(),v.end(),element);
        return *up;
    }

    // inbuilt function for upper bound returns the index of the lower bound element 
    int lbound_index(int element)
    {
        vector<int>::iterator lw= lower_bound(v.begin(),v.end(),element);
        return (lw-v.begin());
    }
    // inbuilt function for upper bound returns the lower bound element 
    int lbound_ele(int elemen)
    {
        vector<int>::iterator lw= lower_bound(v.begin(), v.end(), elemen);
        return *lw;
    }

};
int main() 
{ 
    vector<int> v = {10,20,30,40,50,63};
    Searching sear(v);
    
    cout<<40<<" is present at index "<<sear.lsearch(40)<<endl;
    cout<<40<<" is present at index "<<sear.bsearch(40)<<endl;
    cout<<endl;

    // in built binary search
    cout<<40<<" is not present "<<sear.in_bsearch(49)<<endl;
    cout<<40<<" is present at index "<<sear.in_bsearch(40)<<endl;
    cout<<endl;

    // inbuilt function for upper bound 
    cout<<45<<" is present at upper bound index "<<sear.ubound_index(45)<<endl;
    cout<<52<<" is upper bound element "<<sear.ubound_ele(52)<<endl;
    cout<<endl;

    // inbuilt function for lower bound 
    cout<<45<<" is present at lower bound index "<<sear.lbound_index(45)<<endl;
    cout<<67<<" is lower bound element "<<sear.lbound_ele(67)<<endl;
    cout<<endl;
  
    return 0 ;
}