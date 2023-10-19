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
    long long ss = 0LL;
    // long long maxm = 0;
    long long f = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ss += arr[i];
        if (arr[i] == 1)
            f++;
        // mp[arr[i]]++;
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 && f > 1)
        {
            f--;
            ss -= 2;
        }
        else if (arr[i] != 1)
            ss--;
    }
    if (ss > 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}