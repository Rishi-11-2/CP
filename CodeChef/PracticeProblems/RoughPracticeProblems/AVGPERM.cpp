// https://www.codechef.com/submit/AVGPERM?tab=statement
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
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int b[n];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int t1 = 1;
    int t2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            b[n - t1] = arr[i];
            t1++;
        }
        else
        {
            b[t2 - 1] = arr[i];
            t2++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << el;
}