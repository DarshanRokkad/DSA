// lower triangle matrix => row major matrix
// lower triangle matrix => column major matrix is same the upper triangle matrix => row major matrix
#include <iostream>
using namespace std;
class Upper_tri
{
private:
    int n;
    int *a;

public:
    Upper_tri(int n)
    {
        this->n = n;
        a = new int[n * (n + 1) / 2];
    }

    void set(int row, int col, int x)
    {
        if (row <= col)
        {
            a[((row - 1) * n + (row - 2) * (row - 1) / 2) + (col - row)] = x;
        }
    }

    int get(int row, int col)
    {
        if (row <= col)
        {
            return a[((row - 1) * n + (row - 2) * (row - 1) / 2) + (col - row)];
        }
        else
        {
            return 0;
        }
    }

    friend ostream &operator<<(ostream &o, Upper_tri &m);
    friend istream &operator>>(istream &o, Upper_tri &m);

    ~Upper_tri()
    {
        delete[] a;
    }
};

ostream &operator<<(ostream &o, Upper_tri &m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
            {
                o << m.get(i, j) << ' ';
            }
            else
            {
                o << 0 << " ";
            }
        }
        cout << endl;
    }
    return o;
}

istream &operator>>(istream &o, Upper_tri &m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            cout << "Enter the elements of the at position [" << i << " , " << j << "] : ";
            int x;
            cin >> x;
            m.set(i, j, x);
        }
        cout << endl;
    }
    return o;
}

int main()
{
    cout << "Enter the value of n : ";
    int n;
    cin >> n;

    Upper_tri d(n);
    cin >> d;

    cout << d;

    return 0;
}