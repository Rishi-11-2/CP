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
    int n, c, d;
    cin >> n >> c >> d;
    int arr[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]] = 1;
    }
    vector<int> v;
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] == 1)
        {
            m[arr[i]]--;
            v.push_back(arr[i]);
        }
        else
            cost += c;
    }
    sort(all(v));
    int x = (int)(v.size());
    int cost1 = 0;
    // cout << v[0] << endl;
    if (v[0] == 1)
    {
        x = (int)v.size() - 1;
    }
    else
    {
        cost1 += d;
    }
    cost1 += x * c + cost;
    int curr = 1;
    int res = 0;
    int cc = 0;
    for (auto &it : v)
    {
        cc++;
        if (it == curr)
        {
            curr++;
            continue;
        }
        int n_o = it - curr;
        int acost = n_o * d;
        int dcost = (v.size() - (cc - 1)) * c;
        if (curr == 1)
            dcost += d;
        res += min(dcost, acost);
        // cout << dcost << " " << acost << endl;
        if (dcost < acost)
        {
            break;
        }
        curr = it + 1;
    }
    // cout << cost1 << endl;
    cout << min(res + cost, cost1) << endl;
}