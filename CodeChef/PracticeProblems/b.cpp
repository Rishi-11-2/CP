// https://www.codechef.com/submit/HEIGHTS
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
    ht<int, int> u;
    int largest = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        largest = max(largest, arr[i]);
        u[arr[i]] += 1;
    }
    int count = 0;
    int h = 0;
    for (int i = 0; i < n; i++)
    {
        if (u[arr[i]] <= 1)
        {
            mx = max(arr[i], mx);
            count++;
        }
        if (u[arr[i]] > 2)
            h++;
    }
    if (count == 0)
        cout << 0 << el;
    else if (count == 1)
    {
        if (h > 0 or mx != largest)
        {
            cout << count << el;
        }
        else
        {
            cout << 2 << el;
        }
    }
    else
    {
        if (count % 2 == 0)
            cout << count / 2 << el;

        else
            cout << count / 2 + 1 << el;
    }
}