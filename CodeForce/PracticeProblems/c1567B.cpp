// https://codeforces.com/contest/1567/problem/B
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
vector<int> arr(300000 - 1);
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    arr[0] = 0;
    for (int i = 1; i < 300000 - 1; i++)
    {
        arr[i] = (arr[i - 1]) xor (i);
    }
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
    int a, b;
    cin >> a >> b;
    if (b == arr[a - 1])
    {
        cout << a << el;
        return;
    }
    else
    {
        if (a == 1 and b == 1)
        {
            cout << a + 2 << el;
            return;
        }
        else
        {
            int c = (b) xor (arr[a - 1]);
            if (c == a)
            {
                cout << a + 2 << el;
                return;
            }
            else
            {
                cout << a + 1 << el;
                return;
            }
        }
    }
}