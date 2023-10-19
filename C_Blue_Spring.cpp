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
    long long n, d, p;
    cin >> n >> d >> p;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, greater<long long>());
    long long i = 0;
    long long res = 0LL;
    while (i < n)
    {
        long long j = 1;
        long long s = 0LL;
        while (j <= d && i < n)
        {
            s += arr[i];
            i++;
            j++;
        }
        res += min(s, p);
    }
    cout << res << endl;
}