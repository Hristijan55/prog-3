#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#define N 10
using namespace std;

void Count_sort(vector<int> &a, int exp)
{
    vector<int> out(a.size());
    int count[10] = {0};

    for (int x : a)
    {
        count[(x / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = a.size() - 1; i >= 0; i--)
    {
        int d = (a[i] / exp) % 10;
        out[--count[d]] = a[i];
    }
    a = out;
}

void radix_sort(vector<int> &a)
{
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        Count_sort(a, exp);
    }
}

int main()
{
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 101;
    }
    radix_sort(a);

    for (int x : a)
    {
        cout << x << " ";
    }
    return 0;
}