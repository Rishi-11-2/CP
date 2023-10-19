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
    long long n;
    cin >> n;
    long long arr[n];
    long long s = 0;
    long long flag = 0;
    long long res = 0;
    long long maxm = 0;
    map<long long, long long> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            if (flag == 1)
            {
                res += maxm;
            }
            else
            {
                res += m[0];
            }
            flag = 1;
            m.clear();
            maxm = 0;
        }
        s += arr[i];
        maxm = max(maxm, ++m[s]);
    }
    if (flag == 0)
        res += m[0];
    else
        res += maxm;
    cout << res << endl;
}