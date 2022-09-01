// https://codeforces.com/contest/1352/problem/E
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
    int arr[n];
    vector<int> v1(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v1[arr[i]] += 1;
    }

    if (n == 1 || n == 2)
    {
        cout << 0 << el;
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int s = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            s += arr[j];
            if (s > n)
            {
                break;
            }
            if (v1[s] >= 1)
            {
                count += v1[s];
                v1[s] = 0;
            }
        }
    }
    cout << count << el;
}