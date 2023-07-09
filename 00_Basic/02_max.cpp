// maximum elment of the array and as well as vector using stl
#include<bits/stdc++.h>
using namespace std; 
int main() 
{ 
    vector<int>c{4,6,8,2,1};
    int max = *max_element(c.begin(),c.end());
    cout<<max<<endl;
  
    return 0 ;
}