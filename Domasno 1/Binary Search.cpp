#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    
    *a = *b;
    *b = t;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++, arr++)
    {
        cout << *arr << " ";
    }
}

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(*(arr + j), *(arr + j + 1));
            }
        }
    }
}

int binary_it(int *arr, int size, int target)
{
    int l = 0, r = size - 1, m;
    
    while (l <= r)
    {
        m = (l + r) / 2;

        if (*(arr + m) == target)
        {
            return m;
        }

        if (*(arr + m) > target)
        {
            r = m - 1;
        }

        else
        {
            l = m + 1;
        }
    }

    return -1;
}

int binary_re(int *arr, int l, int r, int target)
{
    if(l <= r)
    {
        int m = (l + r) / 2;

        if (*(arr + m) == target)
        {
            return m;
        }

        if (*(arr + m) > target)
        {
            return binary_re(arr, l, m - 1, target);
        }
        else
        {
            return binary_re(arr, m + 1, r, target);
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {42, 2143, 21, 4222, 1241, 123, 5231, 432, 5212, 521};

    int target = 5212;

    bubble_sort(arr, 10);
    print_arr(arr, 10);
    cout << endl;

    cout << binary_it(arr, 10, target) << endl;
    cout << binary_re(arr, 0, 9, target);

    return 0;
}