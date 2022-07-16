#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll N;
        cin >> n;
        ll a[n];
        int flag = 0;
        int y = 0;
        int h = INT_MAX;
        int j = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            a[i] = (s[i] - '0');
            if (a[i] == 0)
            {
                h = min(h, i);
            }
            if (a[0] == 9)
            {
                y = 1;
            }
            if (a[i] == 9)
            {
                flag++;
            }
        }
        if (a[h - 1] == 1)
        {
            j = 1;
        }
        if (flag == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << 2;
            }
            cout << el;
        }
        else if (y == 1)
        {
            int b[n];
            b[0] = 1;
            for (int i = 1; i < n - 1; i++)
            {
                b[i] = 10 - a[i];
                if (a[i] == 0)
                {
                    b[i] = 0;
                    if (a[i - 1] == 1)
                    {
                        b[i - 1] = 0;
                        int q = 2;
                        while (a[i - q] == 1)
                        {
                            b[i - q] = 0;
                            q++;
                        }
                        b[i - q] = 11 - a[i - q];
                    }
                    else
                    {
                        b[i - 1] = 11 - a[i];
                    }
                }
            }
            b[n - 1] = 11 - a[n - 1];
            for (int i = 0; i < n; i++)
            {
                cout << b[i];
            }
            cout << el;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << 9 - a[i - 1];
            }
            cout << el;
        }
    }
}