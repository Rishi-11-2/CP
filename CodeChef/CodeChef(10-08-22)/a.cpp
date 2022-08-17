#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
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
    int b[n + 1] = {0};
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[arr[i]] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        maxM = max(maxM, b[arr[i]]);
    }
    int p = 0;
    for (int i = 1; i <= n; i++)
    {

        if (maxM == b[i])
            p++;
    }
    if (p == 1)
        cout << "YES" << el;
    else
        cout << "NO" << el;
}