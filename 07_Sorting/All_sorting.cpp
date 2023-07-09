#include <iostream>
using namespace std;
class sorting_type
{
private:
    int *a;
    int size;

public:
    sorting_type()
    {
        create_array();

        cout << endl;
        cout << "Unsorted Array : ";
        print_array();

        sort_array();

        cout << endl;
        cout << "Sorted Array : ";
        print_array();
    }
    // Create an array
    void create_array()
    {
        cout << "Enter number of elements of the array : ";
        cin >> size;
        a = new int[size];
        cout << "Enter the elements of the array : ";
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
    }
    // Prints an array
    void print_array()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl
             << endl;
    }
    // Sort the array based on choice
    void sort_array()
    {
        cout << "--- Sorting Types ---" << endl;
        cout << "1. Bubble sort. " << endl;
        cout << "2. Insertion sort. " << endl;
        cout << "3. Selection sort. " << endl;
        cout << "4. Quick sort. " << endl;
        cout << "Select the sorting type : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            bubble_sort();
            break;
        case 2:
            insertion_sort();
            break;
        case 3:
            selection_sort();
            break;
        case 4:
            quick_sort(0, size - 1);
            break;
        default:
            cout << "Enter correct choice!!!" << endl
                 << endl;
            sort_array();
        }
    }
    // Swapping references
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // 1. Bubble sort
    void bubble_sort()
    {
        for (int i = 0; i < size; i++)
        {
            bool is_sorted = true;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(&a[j], &a[j + 1]);
                    is_sorted = false;
                }
            }
            if (is_sorted)
            {
                break;
            }
        }
    }
    // 2. Insertion sort
    void insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            if (j + 1 != i)
            {
                a[j + 1] = key;
            }
        }
    }
    // 3. Selection sort
    void selection_sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                swap(&a[i], &a[min]);
            }
        }
    }
    // 4. Quick sort
    int partition(int low, int high)
    {
        int pivot = a[low];
        int i = low + 1, j = high;
        while (true)
        {
            while (i < high && a[i] < pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                swap(&a[i], &a[j]);
            }
            else
            {
                swap(&a[low], &a[j]);
                return j;
            }
        }
    }
    void quick_sort(int low, int high)
    {
        if (low < high)
        {
            int j = partition(low, high);
            quick_sort(low, j - 1);
            quick_sort(j + 1, high);
        }
    }
};
int main()
{
    sorting_type s;

    return 0;
}