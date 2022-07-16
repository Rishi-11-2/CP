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
        cin >> n;
        int a[n];
        ll h = 0;
        ll k = 0;
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 0)
            {
                h++;
                if (flag == 1)
                {
                    flag = 0;
                    k += 1;
                }
            }
            else
            {
                flag = 1;
            }
        }
        if (n == 1 and a[0] != 0)
            cout << 1 << el;
        else
        {
            if (a[0] == 0 and a[n - 1] == 0)
                k--;
            if (h == n)
                cout << 0 << el;
            else
                cout << k << el;
        }
    }
}