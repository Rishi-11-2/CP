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
#define INF INT_MAX
void solve(int z);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    int z = 0;
    while (t--)
    {
        solve(++z);
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve(int t)
{
    int n;
    cin >> n;
    int arr[n];
    int b[n];
    ht<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
        b[i] = arr[i];
    }
    sort(b, b + n);
    int c[n] = {-1};
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if ((b[j] <= (2 * arr[i])))
            {
                if (b[j] == arr[i])
                {
                    if (m[arr[i]] == 1)
                    {
                        continue;
                    }
                    c[i] = b[j];
                    break;
                }
                else
                {
                    c[i] = b[j];
                    break;
                }
            }
        }
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
            c[i] = -1;
        cout << c[i] << " ";
    }
    cout << el;
}