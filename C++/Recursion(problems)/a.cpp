#include <bits/stdc++.h>
using namespace std;
int t = 0;
bool ascending(int a[], int n)
{
    if (a[t] < a[++t])
    {
        if (t == n - 2)
            return true;
        ascending(a, n);
    }
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << ascending(a, n);
}