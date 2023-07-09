// Polynomial
#include <iostream>
#include <math.h>
using namespace std;

class Term
{
public:
    int coeff;
    int power;
};

class Polynomial
{
public:
    int n;
    Term *t;
    Polynomial()
    {
        n = 0;
        t = NULL;
    }

    void create()
    {
        cout << "Enter the value of n : ";
        cin >> n;
        t = new Term[n];
        cout << "Enter Polynomial terms : ";
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the coefficient and powerer of " << i + 1 << " term : ";
            cin >> t[i].coeff >> t[i].power;
        }
    }

    void evaluate()
    {
        cout << "Enter the value of x : ";
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (t[i].coeff) * pow(x, t[i].power);
        }
        cout << "Answer for polynomial is " << ans << endl;
    }

    friend ostream &operator<<(ostream &os, Polynomial &p);

    Polynomial operator+(Polynomial po)
    {
        Polynomial ans;
        ans.n = n + po.n;
        ans.t = new Term[ans.n];
        int i = 0, j = 0, k = 0;
        while (i < n && j < po.n)
        {
            if (t[i].power > po.t[j].power)
            {
                ans.t[k++] = t[i++];
            }
            else if (t[i].power < po.t[j].power)
            {
                ans.t[k++] = po.t[j++];
            }
            else
            {
                ans.t[k] = t[i++];
                ans.t[k++].coeff += po.t[j++].coeff;
            }
        }
        while (i < n)
        {
            ans.t[k++] = t[i++];
        }
        while (j < po.n)
        {
            ans.t[k++] = po.t[j++];
        }
        ans.n = k;
        return ans;
    }
};

ostream &operator<<(ostream &os, Polynomial &p)
{
    for (int i = 0; i < p.n; i++)
    {
        os << p.t[i].coeff << "X" << p.t[i].power;
        if (i != p.n - 1)
            os << " + ";
    }
    return os;
}

// sample input : 3 5 4 2 2 5 0 1 5 6 4 5 3 9 2 2 1 3 0  1 1

int main()
{
    Polynomial p1;
    cout << "Enter the polynomial 1 . " << endl;
    p1.create();
    cout << p1 << endl;
    p1.evaluate();

    Polynomial p2;
    cout << "Enter the polynomial 2 ." << endl;
    p2.create();
    cout << p2 << endl;
    p2.evaluate();

    Polynomial p3 = p1 + p2;
    cout << "Sum of 2 polynomial. " << endl;
    cout << " Polynomial 1 : " << p1 << endl;
    cout << " Polynomial 2 : " << p2 << endl;
    cout << " Polynomial 3 : " << p3 << endl;
    p3.evaluate();

    return 0;
}