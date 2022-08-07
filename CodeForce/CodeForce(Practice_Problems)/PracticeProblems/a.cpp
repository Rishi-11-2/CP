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
    cout << n << el;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    if (n == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << el;
            swap(arr[0], arr[1]);
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << el;
            if (i == 0)
                swap(arr[0], arr[1]);
            if (i == 1)
                swap(arr[1], arr[2]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << el;
            swap(arr[n - i - 1], arr[n - i - 2]);
        }
    }
}