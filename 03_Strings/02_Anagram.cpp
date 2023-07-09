// Checking whether 2 strings is anagram or not
#include <iostream>
using namespace std;
int main()
{
    string a = "verbose";
    string b = "observe";
    if (a.length() == b.length())
    {
        int h = 0;
        int x = 0;
        int i ;
        for ( i = 0; i < a.length(); i++)
        {
            x = 1;
            x = x << (a[i] - 'a');
            h = h | x;
        }
        for ( i = 0; i < b.length(); i++)
        {
            x = 1 ;
            x = x<<(b[i]-'a');
            if(!((x&h)==x))
            {
                cout<<"Not a anagram!..."<<endl;
                break;
            }
        }
        if(i==b.length())
        {
            cout<<"Two are anagram..."<<endl;
        }
    }
    else 
    {
        cout<<"Not a anagram!.."<<endl;
    }

    return 0;
}