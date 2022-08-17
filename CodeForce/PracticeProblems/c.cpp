#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int n1 = n;
    int m1 = m;
    int a[n + m], b[n + m] = {-1};
    a[0] = 0;
    n--;
    for (int i = 1; i < n1 + m1; i++)
    {

        if (i % 2 == 0)
        {
            if (a[i - 1] == 0)
            {
                if (n > 0)
                {
                    a[i] = 0;
                    n--;
                }
                else if (m > 0)
                {
                    a[i] = 1;
                    m--;
                }
            }
            else if (a[i - 1] == 1)
            {
                if (m > 0)
                {
                    a[i] = 1;
                    m--;
                }
                else if (n > 0)
                {
                    a[i] = 0;
                    n--;
                }
            }
        }
        else
        {
            if (a[i - 1] == 0)
            {
                if (m > 0)
                {
                    a[i] = 1;
                    m--;
                }
                else if (n > 0)
                {
                    a[i] = 0;
                    n--;
                }
            }
            else if (a[i - 1] == 1)
            {
                if (n > 0)
                {
                    a[i] = 0;
                    n--;
                }
                else if (m > 0)
                {
                    a[i] = 1;
                    m--;
                }
            }
        }
    }
    n = n1;
    m = m1;
    b[0] = 1;
    m--;
    for (int i = 1; i < n1 + m1; i++)
    {

        if (i % 2 == 0)
        {
            if (b[i - 1] == 0)
            {
                if (n > 0)
                {
                    b[i] = 0;
                    n--;
                }
                else if (m > 0)
                {
                    b[i] = 1;
                    m--;
                }
            }
            if (b[i - 1] == 1)
            {
                if (m > 0)
                {
                    b[i] = 1;
                    m--;
                }
                else if (n > 0)
                {
                    b[i] = 0;
                    n--;
                }
            }
        }
        else
        {
            if (b[i - 1] == 0)
            {
                if (m > 0)
                {
                    b[i] = 1;
                    m--;
                }
                else if (n > 0)
                {
                    b[i] = 0;
                    n--;
                }
            }
            if (b[i - 1] == 1)
            {
                if (n > 0)
                {
                    b[i] = 0;
                    n--;
                }
                else if (m > 0)
                {
                    b[i] = 1;
                    m--;
                }
            }
        }
    }
    n = n1;
    m = m1;
    int x1 = 0;
    int x2 = 0;
    int y2 = 0;
    int y1 = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        if (a[i] == a[i + 1])
            x1++;
        else
            y1++;
    }
    for (int i = 0; i < n + m - 1; i++)
    {
        if (b[i] == b[i + 1])
            x2++;
        else
            y2++;
    }

    if (x2 > x1)
    {
        cout << x2 << " " << y2 << el;
    }
    else
    {
        cout << x1 << " " << y1 << el;
    }
}