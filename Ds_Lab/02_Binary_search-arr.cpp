// Binary search using array
#include <iostream>
using namespace std;

class binary_search
{
private:
    int *arr;
    int data;
    int size = 0;

public:
    binary_search()
    {
        input();
        int result = b_search(0, size - 1);
        if (result < 0)
        {
            cout << data << " is not present in the array." << endl;
        }
        else
        {
            cout << data << " is present in " << result << " index." << endl;
        }
    }
    void input()
    {
        cout << "Enter the number of elements of the array : ";
        cin >> size;
        arr = new int[size];
        cout << "Enter the elements of the array in sorted manner : ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the data to be searched : ";
        cin >> data;
    }
    int b_search(int l, int h)
    {
        if (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == data)
            {
                return mid;
            }
            else if (data < arr[mid])
            {
                return b_search(l, mid - 1);
            }
            else
            {
                return b_search(mid + 1, h);
            }
        }
        return -1;
    }
};

int main()
{
    cout<<"**Binary search**"<<endl;
    binary_search b ;

    return 0;
}