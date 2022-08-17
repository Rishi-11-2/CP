// https://codeforces.com/contest/1698/problem/C
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
    vector<int> pos, neg, a;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            pos.pb(x);
        else if (x < 0)
            neg.pb(x);
        else
        {
            if (c <= 2)
            {
                a.pb(x);
                c++;
            }
        }
    }
    if (pos.size() > 2 || neg.size() > 2)
    {
        cout << "NO" << el;
        return;
    }
    for (int i = 0; i < pos.size(); i++)
    {
        a.pb(pos[i]);
    }
    for (int i = 0; i < neg.size(); i++)
    {
        a.pb(neg[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                bool flag = false;
                for (int q = 0; q < a.size(); q++)
                {
                    if (a[i] + a[j] + a[k] == a[q])
                    {
                        flag = true;
                    }
                }
                if (flag == false)
                {
                    cout << "NO" << el;
                    return;
                }
            }
        }
    }
    cout << "YES" << el;
}