// quiz 5 
// #include<bits/stdc++.h>
#include<iostream>
void count(int n)
{
    static int d = 1;
    printf("%d ", n);
    printf("%d ", d);
    d++;
    if (n > 1)
        count(n - 1);

    printf("%d ", d);
}

int main()
{
    count(3);
    return 0;
}