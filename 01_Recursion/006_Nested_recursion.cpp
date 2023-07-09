// Nested recursion
#include <iostream>
using namespace std;
int fun(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
    {
        return fun(fun(n + 11));
    }
}
int main()
{
    cout << fun(95) << endl;
    cout << fun(99) << endl;
    cout << fun(200) << endl;

    return 0;
}