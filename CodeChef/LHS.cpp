#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> lis, pref(n);
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            if (it == lis.size())
                lis.push_back(v[i]);
            else
                lis[it] = v[i];
            pref[i] = lis.size();
        }
        lis.clear();
        vector<int> suff(n);
        for (int i = n - 1; i >= 0; i--)
        {
            auto it = lower_bound(lis.begin(), lis.end(), -v[i]) - lis.begin();
            if (it == lis.size())
                lis.push_back(-v[i]);
            else
                lis[it] = -v[i];
            suff[i] = lis.size();
        }
        int ans = suff[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, suff[i] + pref[i - 1]);
        }
        cout << ans << endl;
        return 0;
    }
}