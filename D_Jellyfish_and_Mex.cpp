#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    set<int> s;
    set<int> x;
    for (int i = 0; i <= n; i++)
    {
        x.insert(i);
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if (x.find(arr[i]) != x.end())
            x.erase(arr[i]);
        s.insert(arr[i]);
    }
    if (*s.begin() != 0)
    {
        cout << 0 << endl;
        return;
    }
    if (mp[0] <= mp[1])
    {
        int s = *x.begin();
        s = s * (mp[0] - 1);
        cout << s << endl;
    }
    else
    {
        int s = *x.begin();
        s = s * (mp[1] - 1) + mp[0];
        cout << s << endl;
    }
}