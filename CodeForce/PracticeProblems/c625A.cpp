#include <bits/stdc++.h>
using namespace std;
#define el endl
#define sp " "
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX;
typedef long double db;
bool isInt(db x) { return ceil(x) == floor(x); }
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n < a and n < b)
    {
        cout << 0 << el;
        return;
    }
    if (a > (b - c) and ((n - b) >= 0))
    {
        int count = ((n - c) / (b - c));
        n -= (count * (b - c));
        count += (n / a);

        cout << count << el;
        return;
    }
    else
    {
        cout << (n / a) << el;
        return;
    }
}