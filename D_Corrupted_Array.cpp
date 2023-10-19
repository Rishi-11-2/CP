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
    long long n;
    cin >> n;
    long long arr[n + 2];
    map<long long, long long> mp;
    long long s = 0;
    for (long long i = 0; i < n + 2; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        s += arr[i];
    }
    long long maxm = 0;
    long long midx = -1;
    for (long long i = 0; i < n + 2; i++)
    {
        if (maxm < arr[i])
        {
            maxm = arr[i];
            midx = i;
        }
    }
    // if (mp[maxm] > 2)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // cout << maxm << endl;
    s -= maxm;
    long long idx = -1;
    for (long long i = 0; i < n + 2; i++)
    {
        if (i == midx)
            continue;
        if ((s - arr[i]) == maxm)
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
    {
        for (long long i = 0; i < n + 2; i++)
        {
            if (i == idx || i == midx)
                continue;
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    s += maxm;
    sort(arr, arr + n + 2);
    maxm = arr[n];
    midx = n;
    s -= maxm;
    idx = -1;
    for (long long i = 0; i < n + 2; i++)
    {
        if (i == midx)
            continue;
        if ((s - arr[i]) == maxm)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << -1 << endl;
        return;
    }
    for (long long i = 0; i < n + 2; i++)
    {
        if (i == idx || i == midx)
            continue;
        cout << arr[i] << " ";
    }
    cout << endl;
}