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
        int a, b, n;
        cin >> a >> b >> n;
        vi d;
        int k = 1;
        int l = a;
        while (l > 0)
        {
            if (((a >> (k - 1)) & 1) != 0)
            {
                d.pb(1);
            }
            else
            {
                d.pb(0);
            }
            k++;
            l /= 10;
        }
        k = 1;
        l = b;
        vi e;
        while (l > 0)
        {
            if (((a >> (k - 1)) & 1) != 0)
            {
                e.pb(1);
            }
            else
            {
                e.pb(0);
            }
            k++;
            l /= 10;
        }
        int h = 0;
        k = 0;
        for (auto &i : d)
        {
            if (i != e[k])
            {
                h++;
            }
        }
        if (h % 2 != 0)
        {
            cout << 1 << el;
        }
        else if (h == 0)
        {
            cout << 0 << el;
        }
        else
        {
            cout << -1 << el;
        }
    }
}