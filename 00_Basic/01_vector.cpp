// vectors in cpp
#include<iostream> 
#include<vector>
using namespace std; 
int main() 
{ 
    vector<int> v ;
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    for(int i = 0;i!=v.size();i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;

    int n = 5 ;
    // This will create the vetor with size n and intialize all elements with 3
    vector<int>a(n,3);
    for(auto x : a )
    {
        cout<<x<<" ";
    }cout<<endl;

    vector<int>c{4,6,8,2,1};
    for(auto x : c )
    {
        cout<<x<<" ";
    }
  
    return 0 ;
}