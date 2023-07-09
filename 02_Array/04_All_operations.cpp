// All the operations of the array menu driven
#include <iostream>
using namespace std;

class Array
{
private:
    int *a;
    int size;
    int length;

public:
    void menu();
    void dothis(int choice);
    void createarray();
    void display();
    void append(int x);
    void insert(int index, int x);
    void deleteele(int index);
    int linear(int key);
    int binary(int key);
    int get(int index);
    void set(int index, int x);
    int max();
    int min();
    int sum();
    float average();
    void reverse();
    void leftshift();
    void rightshift();
    void insertsorted(int x);
    void issorted();
    void movenegative();
    void swap(int i, int j);
};
void Array::menu()
{
    cout << endl << "******************************" << endl;
    cout << "******** ARRAY ********" << endl;
    cout << "1. Create and array." << endl;
    cout << "2. Display an array." << endl;
    cout << "3. Append a element ." << endl;
    cout << "4. Insert an element to the array." << endl;
    cout << "5. Delete element from an array." << endl;
    cout << "6. Linear search." << endl;
    cout << "7. Binary search." << endl;
    cout << "8. Get an element from the array." << endl;
    cout << "9. Set any element to the array." << endl;
    cout << "10. Maximum element of the array." << endl;
    cout << "11. Minmum element of the array." << endl;
    cout << "12. Sum of all the elements of the array." << endl;
    cout << "13. Average element of the array." << endl;
    cout << "14. Reverse the array." << endl;
    cout << "15. Left shift." << endl;
    cout << "16. Right shift." << endl;
    cout << "17. Insert the element to the sorted array." << endl;
    cout << "18. Check whether the array is sorted or not." << endl;
    cout << "19. Move all the -ve elements to the left side of the array." << endl;
    cout << "20. <<<<< Exit >>>>>" << endl;
    cout << "******************************" << endl<< endl;
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;
    dothis(choice);
}
// Do this according to choice
void Array::dothis(int choic)
{
    switch (choic)
    {
    case 1:
    {
        createarray();
    }
    break;
    case 2:
    {
        display();
    }
    break;
    case 3:
    {
        int a;
        cout << "Enter the element you need to append : ";
        cin >> a;
        append(a);
    }
    break;
    case 4:
    {
        int ele;
        int index;
        cout << "Enter the element you need to insert to an array : ";
        cin >> ele;
        cout << "Enter the index you need to insert " << ele << " in array : ";
        cin >> index;
        insert(index, ele);
    }
    break;
    case 5:
    {
        int inde;
        cout << "Enter the index from which you need to delete an element : ";
        cin >> inde;
        deleteele(inde);
    }
    break;
    case 6:
    {
        int key;
        cout << "Enter the element you need to search in the array : ";
        cin >> key;
        int resulti = linear(key);
        if (resulti >= 0)
        {
            cout << key << " is present at index " << resulti << endl;
        }
        else
        {
            cout << key << " is not present the array." << endl;
        }
    }
    break;
    case 7:
    {
        int keyi;
        cout << "Enter the element you need to search in the array : ";
        cin >> keyi;
        int result1 = binary(keyi);
        if (result1 >= 0)
        {
            cout << keyi << " is present at index " << result1 << endl;
        }
        else
        {
            cout << keyi << " is not present the array." << endl;
        }
    }
    break;
    case 8:
    {
        int ind;
        cout << "Enter the index from which you need element : ";
        cin >> ind;
        int re = get(ind);
        if (re != -1)
        {
            cout << "The element at index " << ind << " is " << re << endl;
        }
    }
    break;
    case 9:
    {
        int ind, ele;
        cout << "Enter the element you need to set : ";
        cin >> ele;
        cout << "Enter the index at which you need to  set " << ele << ": ";
        cin >> ind;
        set(ind, ele);
    }
    break;
    case 10:
    {
        cout << "Maximum element of the array is " << max() << endl;
    }
    break;
    case 11:
    {
        cout << "Minimum element of the array is " << min() << endl;
    }
    break;
    case 12:
    {
        cout << "Sum of all the elements of the array is " << sum() << endl;
    }
    break;
    case 13:
    {
        cout << "Average of all the elements of the array is " << average() << endl;
    }
    break;
    case 14:
    {
        reverse();
    }
    break;
    case 15:
    {
        leftshift();
    }
    break;
    case 16:
    {
        rightshift();
    }
    break;
    case 17:
    {
        int elem;
        cout << "Enter the element you need to insert in the sorted array : ";
        cin>>elem;
        insertsorted(elem);
    }
    break;
    case 18:
    {
        issorted();
    }
    break;
    case 19:
    {
        movenegative();
    }
    break;
    case 20:
    {
        exit(0);
    }
    break;
    default:
    {
        cout << "Invalid choice!!" << endl;
        cout << "[Enter the valid choice]" << endl;
    }
    }
}
// Creating an array
void Array::createarray()
{
    cout << "Enter the number of elements of the array : ";
    cin >> length;
    size = length + 10;
    a = new int[size];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < length; i++)
    {
        cin >> a[i];
    }
    display();
}
// To display an element
void Array::display()
{
    cout << "Array : ";
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << endl;
}
// To append an element to an array
void Array::append(int x)
{
    if (length < size)
    {
        a[length++] = x;
        display();
    }
    else
    {
        cout << "You cannot append element to array " << endl
             << "[Array is full]" << endl;
    }
}
// To insert an element to an array at particular index
void Array::insert(int index, int x)
{
    if (length < size)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                a[i] = a[i - 1];
            }
            a[index] = x;
            length++;
            display();
        }
        else
        {
            cout << "You cannot insert an element to an array" << endl
                 << "[Index out of range]" << endl;
        }
    }
    else
    {
        cout << "You cannot insert an element to an array " << endl
             << "[Array is full]" << endl;
    }
}
// Delete an element from an particular index
void Array::deleteele(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
        {
            a[i] = a[i + 1];
        }
        length--;
        display();
    }
    else
    {
        cout << "You cannot delete element from an array" << endl;
        cout << "[Index is out of range]" << endl;
    }
}
// To search an element in an array using linear search technic
int Array::linear(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}
// To search an element in an array  using binary search
int Array::binary(int key)
{
    cout << "***Array should be sorted else you will get wrong answer***" << endl;
    int l = 0;
    int h = length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key < a[mid])
        {
            h = mid - 1;
        }
        else if (key > a[mid])
        {
            l = mid + 1;
        }
        else {
        return mid;
        }
    }
    return -1;
}
// Return an element from a given index
int Array::get(int index)
{
    if (index >= 0 && index < length)
    {
        return a[index];
    }
    else
    {
        cout << "Index is out of range" << endl;
        return -1;
    }
}
// setting an element at given index
void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        a[index] = x;
        display();
    }
    else
    {
        cout << "Index is out of range" << endl;
    }
}
// Returning the maximum element from an array
int Array::max()
{
    int max = a[0];
    for (int i = 0; i < length; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
// Returning the minimum element from an array
int Array::min()
{
    int min = a[0];
    for (int i = 0; i < length; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
// Return the sum of all the elements of the array
int Array::sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
    {
        s += a[i];
    }
    return s;
}
// returning the average of all the elements of the array
float Array::average()
{
    float s = sum();
    float ave = (float)(s / length);
    return ave;
}
// Reversing an array
void Array::reverse()
{
    cout << "Array before reversing : ";
    display();
    for (int i = 0; i < length / 2; i++)
    {
        swap(i, length - 1 - i);
    }
    cout << "Array after reversing : ";
    display();
}
// Left shift of an array
void Array::leftshift()
{
    cout << "Array before lift shift : ";
    display();
    int temp = a[0];
    for (int i = 0; i < length - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[length - 1] = temp;
    cout << "Array after lift shift : ";
    display();
}
// Right shift of an array
void Array::rightshift()
{
    cout << "Array before right shift : ";
    display();
    int temp = a[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = temp;
    cout << "Array after right shift : ";
    display();
}
// Inserting an element in the sorted
void Array::insertsorted(int x)
{
    if (length < size)
    {
        cout << "****The element will be insert to correct position only if array is sorted****" << endl;
        int i = length - 1;
        while (a[i] > x)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = x;
        length++;
        display();
    }
    else
    {
        cout << "You cannot insert an element into an sorted array" << endl
             << "[Array is full]" << endl;
    }
}
// Checking wheater an array is sorted or not
void Array::issorted()
{
    bool s = true;
    for (int i = 0; i < length - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            s = false;
            break;
        }
    }
    if (s)
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
}
// Moving all the negative elements of the array to left side of the array
void Array::movenegative()
{
    cout << "Arrar before movement of -ve elements : ";
    display();
    int i = 0, j = length - 1;
    while (i <= j)
    {
        while (a[i] < 0)
        {
            i++;
        }
        while (a[j] >= 0)
        {
            j--;
        }
        if(i<=j)
        swap(i, j);
    }
    cout << "Arrar after movement of -ve elements : ";
    display();
}
// Swapping the elements from the given to index of the array
void Array::swap(int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    Array a;
    while (1)
    {
        a.menu();
    }

    return 0;
}