// Arithamatic template
#include <iostream>
#include<iomanip>
using namespace std;

template <class T>
class calculate
{
private:
    T n1, n2;

public:
    calculate(T a, T b)
    {
        n1 = a;
        n2 = b;
    }
    void display()
    {
        cout << "Add : " << add() << endl;
        cout << "Sub : " << sub() << endl;
        cout << "Multi : " << multi() << endl;
        cout << "Divide : " <<setprecision(3)<< div() << endl;
    }
    T add()
    {
        return (n1 + n2);
    }
    T sub()
    {
        return (n1 - n2);
    }
    T multi()
    {
        return (n1 * n2);
    }
    T div()
    {
        return (n1 / n2);
    }
};
int main()
{
    calculate<int> c(9,3);
    cout<<"For integer "<<endl;
    c.display();

    cout<<endl;
    calculate<float> f(6.3,4.8);
    cout<<"Floating point "<<endl;
    f.display();

    return 0;
}