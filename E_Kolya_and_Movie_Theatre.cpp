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
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n, m, d;
    cin >> n >> m >> d;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    multiset<long long> s;
    long long sum = 0;
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        long long curr = sum + arr[i] - d * (i + 1);
        res = max(res, curr);
        if (arr[i] > 0)
        {
            sum += arr[i];
            s.insert(arr[i]);
            if (s.size() >= m)
            {
                sum -= *s.begin();
                s.erase(s.begin());
            }
        }
    }
    cout << res << endl;
}