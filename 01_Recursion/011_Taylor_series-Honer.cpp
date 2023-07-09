// Honer rule
#include <iostream>
using namespace std;

// method 1 in iterative
double e(int x , int n )
{
    double s = 1 ;
    for(;n>0;n--)
    {
        s=1+(x*s/n);
    }
    return s;
}

// method 2 in recursion
// double e(int x, int n)
// {
//     static double s = 1;
//     if (n == 0)
//     {
//         return s;
//     }
//     s = 1 + x  * s/ n;
//     return e(x, n - 1);
// }

int main()
{
    cout << e(1, 10);

    return 0;
}