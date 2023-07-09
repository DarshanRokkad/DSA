// Diagonal matrix
#include <iostream>
using namespace std;
class Diagonal_matrix
{
private:
    int n;
    int *a;

public: 
    Diagonal_matrix(int n)
    {
        this->n = n;
        a = new int[n];
    }

    void set(int row, int col, int x)
    {
        if (row == col)
        {
            a[row] = x;
        }
    }

    int get(int row, int col)
    {
        if (row == col)
        {
            return a[row];
        }
        else
        {
            return 0;
        }
    }

    friend ostream &operator<<(ostream &o, Diagonal_matrix &m);

    ~Diagonal_matrix()
    {
        delete[] a;
    }
};
ostream &operator<<(ostream &o, Diagonal_matrix &m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
            {
                o << m.a[i] << ' ';
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

int main()
{
    Diagonal_matrix d(4);
    d.set(0, 0, 5);
    d.set(1, 1, 8);
    d.set(2, 2, 2);
    d.set(3, 3, 9);

    cout << d.get(3, 3) << endl;
    cout << d.get(2, 3) << endl;

    cout << d;

    return 0;
}