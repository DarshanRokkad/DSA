#include <iostream>
using namespace std;
template <typename T, typename U>
U add(T x, U y)
{
    return (x + y);
}
int main()
{
    cout << "Addition of 2 integer numbers: " << add<int, float>(5, 4) << endl;
    cout << "Addition of 2 float numbers: " << add<float>(5.3f, 4.5f) << endl;
    cout << "Addition of 2 double numbers: " << add<double>(5.3, 4.5) << endl;
    return 0;
}
