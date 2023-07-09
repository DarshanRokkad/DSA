#include <iostream>
using namespace std;

class Pattern_replace
{
private:
    string str, rep, ptr, ans;

public:
    Pattern_replace()
    {
        input();
        replace();
    }
    void input()
    {
        cout << "Enter the string : ";
        cin >> str;
        cout << "Enter the pattern : ";
        cin >> ptr;
        cout << "Enter the string that has to be replaced : ";
        cin >> rep;
    }
    void replace()
    {
        bool flag = false;
        int i = 0;
        while (str[i] != '\0')
        {
            int j = 0;
            while (str[i + j] == ptr[j] && ptr[j] != '\0')
            {
                j++;
            }
            if (ptr[j] == '\0')
            {
                flag = true;
                ans += rep;
                i = i + (j - 1);
            }
            else
            {
                ans += str[i];
            }
            i++;
        }
        if (flag)
        {
            cout << "Edited string : " << ans << endl;
        }
        else
        {
            cout << "Pattern donot exist . " << endl;
        }
    }
};

int main()
{
    Pattern_replace p ;

    return 0 ;
}