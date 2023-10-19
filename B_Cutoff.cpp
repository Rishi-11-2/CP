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

    solve();
}
void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v;
    for (long long i = 0; i < n - 1; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    for (long long i = 0; i <= 100; i++)
    {
        long long s1 = 0;
        auto b = v;
        b.push_back(i);
        sort(all(b));
        for (long long j = 1; j < n - 1; j++)
        {
            s1 += b[j];
        }
        if (s1 >= x)
        {
            // cout << i << " " << s1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}