#include <iostream>
using namespace std;

const int n = 8;

void place_queen(int a[n][n], int k, int l)
{
    int c = k, d = l;
    while (l >= 0)
    {
        a[k][l]++;
        l--;
    }
    l = d;

    while (k < n)
    {
        a[k][l]++;
        k++;
    }
    k = c;

    while (l < n)
    {
        a[k][l]++;
        l++;
    }
    l = d;

    while (k >= 0)
    {
        a[k][l]++;
        k--;
    }
    k = c;

    while (k < n && l >= 0)
    {
        a[k][l]++;
        k++;
        l--;
    }
    k = c;
    l = d;

    while (k < n && l < n)
    {
        a[k][l]++;
        k++;
        l++;
    }
    k = c;
    l = d;

    while (k >= 0 && l < n)
    {
        a[k][l]++;
        k--;
        l++;
    }
    k = c;
    l = d;

    while (k >= 0 && l >= 0)
    {
        a[k][l]++;
        k--;
        l--;
    }
    k = c;
    l = d;

    a[k][l] -= 7;

}

void remove_queen(int a[n][n], int k, int l)
{
    int c = k, d = l;

    while (l >= 0)
    {
        a[k][l]--;
        l--;
    }
    l = d;

    while (k < n)
    {
        a[k][l]--;
        k++;
    }
    k = c;

    while (l < n)
    {
        a[k][l]--;
        l++;
    }
    l = d;

    while (k >= 0)
    {
        a[k][l]--;
        k--;
    }
    k = c;

    while (k < n && l >= 0)
    {
        a[k][l]--;
        k++;
        l--;
    }
    k = c;
    l = d;

    while (k < n && l < n)
    {
        a[k][l]--;
        k++;
        l++;
    }
    k = c;
    l = d;

    while (k >= 0 && l < n)
    {
        a[k][l]--;
        k--;
        l++;
    }
    k = c;
    l = d;

    while (k >= 0 && l >= 0)
    {
        a[k][l]--;
        k--;
        l--;
    }
    k = c;
    l = d;

    a[k][l] += 7;
}

int solve (int a[n][n], int col)
{
    if (col == n)
    {
        return 1;
    }

    int br = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][col] == 0)
        {
            place_queen(a, i, col);
            br += solve(a, col + 1);
            remove_queen(a, i, col);
        }
    }
    return br;
}

int main()
{
    int a[n][n];
    int z = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    cout << "Ima vkupno : " << solve(a, 0) << " Nacini da se postavat kralicite";
    return 0;
}