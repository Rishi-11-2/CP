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
        bool flag = 0;
        vi b;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 0)
            {
                b.pb(i);
            }
        }
        int cnt = count(a, a + n, 0);
        k = 0;
        if (cnt == n)
        {
            cout << 0 << el;
        }
        else if (cnt == 0)
        {
            cout << 1 << el;
        }
        else
        {
            for (int i = 0; i < (b.size()) - 1; i++)
            {
                if ((b[i + 1] - b[i]) > 1)
                {
                    k++;
                }
            }
            if (b[0] != 0)
            {
                k++;
            }
            if (b[b.size() - 1] != n - 1)
            {
                k++;
            }
            if (k == 1)
            {
                cout << 1 << el;
            }
            else
            {
                cout << 2 << el;
            }
        }
    }
}