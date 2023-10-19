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
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (auto &x : v)
        out << x << ' ';
    return out;
}
double PI = acos(-1);
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
    int sp = 0;
    vector<int> a;
    vector<vector<int>> b;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vector<int> v;
        for (int i = 0; i < x; i++)
        {
            int y;
            cin >> y;
            v.push_back(y);
            a.push_back(y);
        }
        b.push_back(v);
    }
    int m = a.size();
    sort(all(a));
    map<int, int> m1;
    for (int i = 0; i < m - 1; i++)
    {
        if (i + 1 < m)
            m1[a[i]] = a[i + 1];
    }
    // cout << m1[3] << endl;
    for (auto it : b)
    {
        int p = it.size();
        for (int i = 0; i < p - 1; i++)
        {
            if (m1[it[i]] != it[i + 1])
                sp++;
        }
    }
    cout << sp << " " << sp + n - 1 << endl;
}