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
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
int32_t main()
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
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0;
    int high = n - 1;
    int prev = arr[low];
    int a = arr[low];
    low++;
    int b = 0;
    int c = 1;
    while (low <= high)
    {
        if (c % 2 != 0)
        {
            c++;

            int s = 0;
            cout << high << el;
            while (s <= prev)
            {
                if (low == high)
                {
                    s += arr[high];
                    b += s;
                    break;
                }
                s += arr[high];
                high--;
            }

            b += s;
            prev = s;
        }
        else
        {

            c++;
            int s = 0;
            cout << low << el;
            while (s <= prev)
            {
                if (low == high)
                {
                    s += arr[low];
                    a += s;
                    break;
                }
                s += arr[low];
                low++;
            }

            a += s;
            prev = s;
        }
    }
    cout << c << " " << a << " " << b << el;
}