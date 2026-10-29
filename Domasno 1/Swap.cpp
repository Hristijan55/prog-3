#include <iostream>
using namespace std;

void swap_ptr(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_ref(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a, b;
    cin >> a >> b;

    swap_ptr(&a, &b);
    cout << a << " " << b << endl;

    swap_ref(a, b);
    cout << a << " " << b;

    return 0;
}