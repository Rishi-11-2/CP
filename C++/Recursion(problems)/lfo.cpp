#include <bits/stdc++.h>
using namespace std;
int hi = INT_MIN;
int li = INT_MAX;
int t = 0;
void occur(int a[], int b, int n)
{
    if (a[t] == b)
    {
        if (hi < t)
            hi = t;

        if (li > t)
            li = t;
    }
    t++;
    if (t == n)
    {
        return;
    }
    occur(a, b, n);
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
    int b;
    cin >> b;
    occur(a, b, n);
    cout << hi << " " << li;
}
