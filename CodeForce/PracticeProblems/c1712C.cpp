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
#define ll long long int
#define lld long double
#define INF INT_MAX
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
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
    int arr[n];
    ht<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]] = 0;
    }
    int index = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i + 1] < arr[i])
        {
            index = i;
            break;
        }
    }
    for (int i = 0; i <= index; i++)
    {
        m[arr[i]] = 1;
    }
    int x = 0;
    for (int i = n - 1; i > index; i--)
    {
        if (m[arr[i]] == 1)
        {
            x = i;
            break;
        }
    }
    for (int i = x; i > index; i--)
    {
        m[arr[i]] = 1;
    }
    x = 0;
    for (auto it : m)
    {
        if (it.second == 1)
            x++;
    }
    cout << x << el;
}