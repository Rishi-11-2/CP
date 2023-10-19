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
    int arr[n];
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxM = max(maxM, arr[i]);
    }
    int maxI = 0;
    int x = log2(maxM);
    vector<int> v;
    for (int i = 0; i <= x; i++)
        v.push_back(INT_MAX);
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] & (1 << i)) != 0)
            {
                v[i] = min(v[i], arr[j]);
            }
        }
    }
    // cout << v << el;
    //  cout << maxI << el;
    int a1 = -1;
    int c = 0;
    int maxV = 0;
    int res = 0;
    for (int i = 0; i <= x; i++)
    {
        maxV = 0;
        for (int j = 0; j < n; j++)
        {

            if ((v[i] != arr[j]) && (arr[j] & ((1 << i))) == 0)
            {
                a1 = arr[j] | (1 << i);
                // cout << a1 << el;
                maxV = max(maxV, a1);
            }
        }
        // cout << maxV << el;
        int f = v[i] & ~(1 << i);
        // cout << maxV << " " << f << el;
        int g = *min_element(arr, arr + n);
        int p = min(g, f);
        res = max(res, maxV - p);

        c++;
    }
    cout << res << el;
}