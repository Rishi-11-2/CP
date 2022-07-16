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
        lld x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << (ll)x << el;
        }
        else
        {
            lld f = x;
            x = min(x, y);
            y = max(f, y);
            int b = (y / x);
            ll a = log2(b);
            ll c = floor(log2f(y / x));
            ll d = ceil(log2f(y / x));
            if (c == d)
            {
                cout << (a + y) << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}