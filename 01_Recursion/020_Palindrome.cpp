// Check the string is Palindrome 
#include<iostream> 
using namespace std; 
bool isPalindrome(string n , int start , int end)
{
    if(start<=end)
    {
        if(n[start]!=n[end])
        {
            return false ;
        }
        return isPalindrome(n,start+1,end-1);
    }
    return true;
}
int main() 
{ 
    string str ;
    cout<<"Enter the string is palindrome or not : ";
    cin>>str;
    if(isPalindrome(str,0,str.length()-1))
    {
        cout<<str<<" is a Palindrome"<<endl;
    }
    else
    {
        cout<<str<<" is not a Palindrome"<<endl;
    }
  
    return 0 ;
}