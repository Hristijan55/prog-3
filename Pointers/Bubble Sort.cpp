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
        for (int j = 0; j < size - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(*(arr + j), *(arr + j + 1));
            }
        }
    }
}

int main()
{
    int arr[10] = {42, 2143, 21, 4222, 1241, 123, 5231, 432, 5212, 521};

    bubble_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}