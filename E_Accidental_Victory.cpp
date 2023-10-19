#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin >> n;
    long long arr[n];
    set<long long> s;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    map<long long, bool> check;
    vector<long long> v(all(s));
    long long nn = v.size();
    long long maxm = v[nn - 1];
    check[v[nn - 1]] = 1;
    vector<long long> pref(nn, 0);
    pref[0] = mp[v[0]] * v[0];
    for (long long i = 1; i < nn; i++)
    {
        // cout << pref[i - 1] + v[i] << endl;
        pref[i] = pref[i - 1] + v[i] * mp[v[i]];
    }
    long long x = 1LL;
    for (long long i = nn - 2; i >= 0; i--)
    {
        if (x == 1 && pref[i] >= v[i + 1])
            check[v[i]] = 1;
        else
            x = 0;
    }
    vector<long long> res;
    for (long long i = 0; i < n; i++)
    {
        if (check[arr[i]] == 1)
            res.push_back(i + 1);
    }
    cout << (long long)(res.size()) << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}