#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
vector<long long> m(1000002, 0);

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
    // map<long long, long long> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << m[arr[i]] << " ";
    // }
    long long c = 0;
    for (long long i = 0; i < n; i++)
    {
        c += (m[arr[i]] - 1) * (m[arr[i]] - 2);
        for (long long j = 2; arr[i] * j * j <= 1000000; j++)
        {

            c += m[arr[i] * j] * m[arr[i] * j * j];
        }
    }
    for (int i = 0; i < n; i++)
        m[arr[i]] = 0;
    cout << c << endl;
}