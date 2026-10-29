#include <iostream>
using namespace std;

void print_arr (int *a, int size)
{
    for (int i = 0; i < size; i++, a++)
    {
        cout << *a << " ";
    }
}

int main()
{
    int a[5] = {5, 123, 12, 42, 412};
    print_arr(a, 5);
    
    return 0;
}