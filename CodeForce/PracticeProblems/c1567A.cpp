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
    int n;
    cin >> n;
    string s;
    cin >> s;

    string z = string(n, '1');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L' || s[i] == 'R')
        {
            z[i] = s[i];
        }
        if (s[i] == 'U')
            z[i] = 'D';
        if (s[i] == 'D')
            z[i] = 'U';
    }
    cout << z << el;
}