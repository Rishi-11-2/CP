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
set<int> s;
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
void mergeA(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int maxM = *(max_element(arr + l, arr + r));
    int minM = *(min_element(arr + l, arr + r));
    int mid = (maxM + minM) / 2;
    int p = upper_bound(arr + l, arr + r, mid) - arr;
    // int s1 = accumulate(arr + l, arr + p, 0LL);
    // int s2 = accumulate(arr + p + 1, arr + r, 0LL);
    int s1 = 0;
    int s2 = 0;
    for (int i = l; i <= p; i++)
    {
        s1 += arr[i];
    }
    for (int i = p + 1; i <= r; i++)
    {
        s2 += arr[i];
    }
    s.insert(s1);
    s.insert(s2);
    mergeA(arr, l, p);
    mergeA(arr, p + 1, r);
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
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    mergeA(arr, 0, n - 1);
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (s.find(x) != s.end())
            cout << "YES" << el;
        else
            cout << "NO" << el;
    }
    s.erase(s.begin(), s.end());
}