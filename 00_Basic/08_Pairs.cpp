// Storing of name and usn of a student in the pair stl 
#include<iostream> 
using namespace std; 
int main() 
{ 
    int n ;
    cout<<"Enter the number of student in the class : ";
    cin>>n;
    pair<string,string> p[n];
    char count = '0' ;
    for(int i = 0 ;i<n ;i++)
    {
        string usn = "1NT21CS";
        cout<<"Enter the name of the student "<<(i+1)<<" : ";
        cin>>p[i].first;
        usn +=(++count);
        p[i].second=usn;
    }
    cout<<endl;
    cout<<"Student and USN "<<endl;
    for(int i = 0 ;i<n ;i++)
    {
        cout<<p[i].first<<" : "<<p[i].second<<endl;
    }

    return 0 ;
}