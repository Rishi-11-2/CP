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
    int g = INT_MAX;
    int h = 0;
    int prefix[n];
    int suffix[n];
    bool flag = true;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] < prefix[i - 1] and arr[i] < suffix[i + 1])
            flag = false;
    }
    cout << (flag == false ? "NO" : "YES") << el;
}