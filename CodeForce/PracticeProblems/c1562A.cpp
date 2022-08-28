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
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int l, r;
    cin >> l >> r;
    if (l == r)
    {
        cout << 0 << el;
        return;
    }
    int a = r / 2;
    int b = r;
    if (b % 2 != 0)
    {
        b++;
        a = (b / 2);
        if (a < l)
        {
            a = l;
        }
        cout << (r) % (a) << el;
        return;
    }
    else
    {
        b = r - 1;
        a = (r / 2);
        if (a < l)
        {
            a = l;
            b = r;
        }
        cout << (b % a) << el;
    }
}