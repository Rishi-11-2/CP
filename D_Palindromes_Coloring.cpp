#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
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
}
void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        mp[s[i] - 'a']++;
    }
    int c1 = 0;
    int c2 = 0;
    for (auto it : mp)
    {
        c1 += it.second / 2;
        c2 += it.second % 2;
    }
    int res = 2 * (c1 / k);
    c2 += 2 * (c1 % k);
    if (c2 >= k)
        res++;
    cout << res << endl;
}