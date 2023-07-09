// Rope cutting
#include <iostream>
using namespace std;
int maxpeices(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = max(maxpeices(n - a, a, b, c), max(maxpeices(n - b, a, b, c), maxpeices(n - c, a, b, c)));
    if(res==-1)
    {
        return -1 ;
    }
    return res+1 ;
}
int main()
{
    cout<<maxpeices(23,11,9,12)<<endl;

    return 0;
}