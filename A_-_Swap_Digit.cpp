
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> x;
    vector<int> y;
    while (a > 0)
    {
        x.push_back(a % 10);
        a /= 10;
    }
    while (b > 0)
    {
        y.push_back(b % 10);
        b /= 10;
    }
    int n1 = x.size();
    int M = 998244353;
    // reverse(all(x));
    // reverse(all(y));
    int c = 0;
    int d = 0;
    for (int i = n1 - 1; i >= 0; i--)
    {
        if (i != n1 - 1)
        {
            if (x[i] > y[i])
            {
                c += (pow(10, i)) * y[i];
                d += (pow(10, i)) * x[i];
            }
            else
            {
                c += (pow(10, i)) * x[i];
                d += (pow(10, i)) * y[i];
            }
        }
        else
        {
            c += pow(10, i) * x[i];
            d += pow(10, i) * y[i];
        }
    }
    // cout << c << " " << d << endl;
    cout << ((c % M) * (d % M)) % M;
}