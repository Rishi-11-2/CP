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
    int arr[n][2];
    int maxR = 0;
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        maxR = max(arr[i][0], arr[i][1]);
        maxM = max(maxM, maxR);
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == maxM || arr[i][1] == maxM)
        {
            index = i;
            break;
        }
    }
    int s = 0;
    s += (maxM * 2);
    for (int i = 0; i < n; i++)
    {
        s += (2 * min(arr[i][0], arr[i][1]));
    }
    cout << s << el;
}