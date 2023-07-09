// Getting the permutation of the a string
#include <iostream>
#include <string.h>
using namespace std;
// Here we use the concept of recursion , backtracking and brute force
// void perm(char s[], int k)
// {
//     static int a[10] = {0};
//     static char res[10];
//     int i;
//     if (s[k] == '\0')
//     {
//         res[k] = '\0';
//         cout << res << endl;
//     }
//     else
//     {
//         for (i = 0; s[i] != '\0'; i++)
//         {
//             if (a[i] == 0)
//             {
//                 res[k] = s[i];
//                 a[i] = 1;
//                 perm(s, k + 1);
//                 a[i] = 0;
//             }
//         }
//     }
// }
// Second solution 
void perm(char s[],int l ,int h)
{
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i = l ;i<=h;i++)
        {
            swap(s[l],s[i]);
            perm(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main()
{
    char str[] = "ABC";
    perm(str, 0,2);

    return 0;
}