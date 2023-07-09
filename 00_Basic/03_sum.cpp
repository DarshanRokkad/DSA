// sum of all the elements of the array or vetor using inbuilt function 
#include<iostream> 
#include<vector>
#include<numeric>
using namespace std; 
int main() 
{ 
    vector<int>c{4,6,8,2,1};
    int s = accumulate(c.begin(),c.end(),s);
    cout<<s<<endl;
  
    return 0 ;
}