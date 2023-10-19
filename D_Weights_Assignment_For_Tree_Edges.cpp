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
    vector<long long> parent(n + 1, -1);
    long long ulp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == i + 1)
            ulp = i + 1;
        parent[i + 1] = arr[i];
    }
    long long b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<long long> dist(n + 1, -1);
    if (b[0] != ulp)
    {
        cout << -1 << endl;
        return;
    }
    dist[b[0]] = 0;
    long long c = 1LL;
    for (int i = 1; i < n; i++)
    {
        if (dist[parent[b[i]]] == -1)
        {
            cout << -1 << endl;
            return;
        }
        dist[b[i]] = c;
        c = dist[b[i]] + 1LL;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << abs(dist[arr[i - 1]] - dist[i]) << " ";
    }
    cout << endl;
}