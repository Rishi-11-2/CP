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
    long long n, s1, s2;
    cin >> n >> s1 >> s2;
    long long r[n];
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        v.push_back({r[i], (i + 1)});
    }
    // for (auto &it : v)
    //     cout << it.first << " " << it.second << endl;
    sort(all(v));
    long long tc1 = 0;
    long long tc2 = 0;
    vector<long long> lista;
    vector<long long> listb;
    int ca = 1;
    int cb = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        long long cost1 = s1 * (lista.size() + 1);
        long long cost2 = (listb.size() + 1) * s2;
        // cout << tc1 << " " << tc2 << endl;
        if (cost1 > cost2)
        {
            listb.push_back(v[i].second);
        }
        else
        {
            lista.push_back(v[i].second);
        }
    }
    // cout << endl;
    cout << lista.size() << " ";
    for (auto &it : lista)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << listb.size() << " ";
    for (auto &it : listb)
        cout << it << " ";
    cout << endl;
}