// lower triangle matrix => row major matrix
#include <iostream>
using namespace std;
class lower_tri
{
private:
    int n;
    int *a;

public:
    lower_tri(int n)
    {
        this->n = n;
        a = new int[n * (n + 1) / 2];
    }

    void set(int row, int col, int x)
    {
        if (row >= col)
        {
            a[(row * (row - 1) / 2) + (col - 1)] = x;
        }
    }

    int get(int row, int col)
    {
        if (row >= col)
        {
            return a[(row * (row - 1) / 2) + (col - 1)];
        }
        else
        {
            return 0;
        }
    }

    friend ostream &operator<<(ostream &o, lower_tri &m);
    friend istream &operator>>(istream &o, lower_tri &m);

    ~lower_tri()
    {
        delete[] a;
    }
};

ostream &operator<<(ostream &o, lower_tri &m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            o << m.get(i, j) << " ";
        }
        cout << endl;
    }
    return o;
}

istream &operator>>(istream &o, lower_tri &m)
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
    cout<<"Enter the value of n : ";
    int n ; cin>>n ; 
    lower_tri d(n);
    cin >> d;

    cout << d;

    return 0;
}