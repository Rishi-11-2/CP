#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> begin;
    vector<int> last;
    vector<int> v;
    for (int i = 1; i < n; i += 2)
    {
        begin.push_back(arr[i]);
        last.push_back(arr[i + 1]);
        v.push_back(arr[i + 1] - arr[i]);
    }
    int q;
    cin >> q;
    vector<int> pre(v.size(), 0);
    vector<int> suf(v.size(), 0);
    pre[0] = v[0];
    int s = 0;
    s += v[0];
    for (int i = 1; i < v.size(); i++)
    {
        pre[i] = v[i] + pre[i - 1];
        s += v[i];
    }
    suf[v.size() - 1] = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + v[i];
    }
    vector<int> res;
    // cout << s << endl;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        auto j = lower_bound(all(last), x) - last.begin();
        auto k = upper_bound(all(begin), y) - begin.begin();
        k = k - 1;
        int sum = s;
        sum -= pre[j];
        sum -= suf[k];
        cout << j << " " << k << endl;
        // cout << pre[j] << " " << suf[k] << endl;
        // cout << last[j] - x << " " << y - begin[k] << endl;
        sum += (last[j] - x);
        sum += (y - begin[k]);
        res.push_back(sum);
    }
    for (auto it : res)
        cout << it << endl;
}