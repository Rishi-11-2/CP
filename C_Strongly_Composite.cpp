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
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int x = arr[i];
        while (x % 2 == 0)
        {
            m[2]++;
            x = x / 2;
        }
        for (int i = 3; i <= sqrt(x); i++)
        {
            while (x % i == 0)
            {
                m[i]++;
                x = x / i;
            }
        }
        if (x > 2)
            m[x]++;
    }
    int cc = 0;
    int res = 0;
    for (auto &it : m)
    {
        res += (it.second / 2);
        if (it.second % 2)
        {
            cc++;
        }
        if (cc == 3)
        {
            cc = 0;
            res++;
        }
    }
    cout << res << endl;
}