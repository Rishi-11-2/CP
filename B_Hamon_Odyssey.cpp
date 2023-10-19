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
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long c = INT_MAX;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {

        c = c & arr[i];
        if (c == 0)
        {
            res++;
            c = INT_MAX;
        }
    }
    cout << max(res, 1LL) << endl;
}