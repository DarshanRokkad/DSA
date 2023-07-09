// minimum number of notes required to sum up to some amount
#include<iostream> 
#include<vector>
using namespace std; 
int main() 
{ 
    int amount ;
    cout<<"Enter the amount : ";
    cin>>amount;
    // number of 500 , 100 , 50 , 20 , 10 , 5 , 2 , 1 
    vector<int>v ;
    int n ;

    n=amount/500;
    v.push_back(n);    
    amount-=n*500;

    n=amount/100;
    v.push_back(n);    
    amount-=n*100;

    n=amount/50;
    v.push_back(n);    
    amount-=n*50;

    n=amount/20;
    v.push_back(n);    
    amount-=n*20;

    n=amount/10;
    v.push_back(n);    
    amount-=n*10;

    n=amount/5;
    v.push_back(n);    
    amount-=n*5;

    n=amount/2;
    v.push_back(n);    
    amount-=n*2;

    v.push_back(amount);   

    // printing the output ;
    // for(auto x : v)
    // {
    //     cout<<x<<" ";
    // }
    cout<<"500 100 50 20 10 5 2 1"<<endl;
    for(int i = 0 ;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
  
    return 0 ;
}