// https://codeforces.com/contest/1701/problem/C
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
}
bool check(int t, int n, vector<int> cnt)
{
    ll fr = 0;
    ll m = 0;
    for (int i = 0; i < n; i++)
    {
        if (t >= cnt[i])
            fr += (t - cnt[i]) / 2;
        else
            m += cnt[i] - t;
    }
    return m <= fr;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    vector<int> cnt(n);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        --arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        ++cnt[arr[i]];
    }
    int low = 0;
    int high = m * 2;
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid, n, cnt) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << res << el;
}