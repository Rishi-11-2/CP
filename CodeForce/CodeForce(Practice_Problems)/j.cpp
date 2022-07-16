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
    int t;
    cin >> t;
    while (t--)
    {
        lld n;
        cin >> n;
        ll a[(int)n];
        unordered_map<int, int> h;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            h[a[i]] += 1;
        }
        bool flag = 0;
        int maxw = 1;
        int s = 0;
        for (ll i = 0; i < n; i++)
        {
            maxw = max(maxw, h[a[i]]);
            s += h[a[i]];
        }
        lld h1 = ceil(n / 2);
        if (maxw < (int)h1 and maxw != 1)
        {
            cout << ((int)(n / maxw) + 1) << endl;
        }
        else if (s == n and maxw != 1)
        {

            cout << ((int)(n / maxw) - 1) << endl;
        }
        else
        {
            cout << (int)(n / maxw) << endl;
        }
    }
}