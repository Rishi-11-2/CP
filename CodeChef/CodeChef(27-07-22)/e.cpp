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
    ht<int, int> v;
    uset<int> u;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[arr[i]] += 1;
    }
    if (v[arr[0]] == n)
    {
        if (n % 2 == 0)
        {
            cout << (n / 2) << el;
        }
        else
        {
            cout << (n / 2) + 1 << el;
        }
    }
    else
    {
        int maxZ = 0;
        int f = 0;
        int max2 = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {

            maxZ = max(v[arr[i]], maxZ);
        }
        for (int i = 0; i < n; i++)
        {
            if (v[arr[i]] != (maxZ))
            {
                max2 = max(max2, v[arr[i]]);
            }
            if (v[arr[i]] == maxZ and flag == 0)
            {
                f = arr[i];
                flag = 1;
            }
            if (v[arr[i]] == maxZ and arr[i] != f)
            {
                flag = 2;
            }
        }
        if (flag == 2)
        {
            cout << maxZ << el;
        }
        else if (max2 > (maxZ / 2))
        {
            cout << max2 << el;
        }
        else
        {
            if (maxZ % 2 == 0)
            {
                cout << maxZ / 2 << el;
            }
            else
            {
                cout << maxZ / 2 + 1 << el;
            }
        }
    }
}