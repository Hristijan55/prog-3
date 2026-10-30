#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Count_sort(vector<string> &a, int pos)
{
    vector<string> out(a.size());
    int count[257] = {0};

    for (const string& x : a)
    {
        if (pos >= (int)x.size())
        {
            count[0]++;
        }
        else
        {
            count[(unsigned char)x[pos] + 1]++;
        }
    }

    for (int i = 1; i < 257; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        int k;
        if (pos >= (int)a[i].size())
        {
            k = 0;
        }
        else
        {
            k = (unsigned char)a[i][pos] + 1;
        }

        count[k]--;
        out[count[k]] = a[i];
    }

    a = out;
}

void radix_sort(vector<string>& a)
{
    int mx = 0;
    for (const string& x : a)
    {
        mx = max(mx, (int)x.size());
    }
    for (int pos = mx - 1; pos >= 0; pos--)
    {
        Count_sort(a, pos);
    }
}

int main()
{
    vector<string> a = {"banana", "apple", "cherry", "app", "bandana", "apricot", "car", "card"};

    radix_sort(a);;

    for (const string& x : a)
    {
        cout << x << endl;
    }

    return 0;
}