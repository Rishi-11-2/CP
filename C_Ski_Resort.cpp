#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
// vector<int> fact(200002, 0);

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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= q)
        {
            x++;
        }
        else if (arr[i] > q)
        {
            if (x >= k)
            {
                // cout << x << endl;
                v.push_back(x);
            }
            x = 0;
        }
    }
    if (x != 0 && x >= k)
        v.push_back(x);
    long long res = 0;
    for (auto it : v)
    {
        long long u = 1;
        u = (it - (k));
        u++;
        long long h = u * (u + 1);
        h = h / 2;
        res += h;
        // else res += 1;
    }
    // if (v.size() > 1)
    //     res -= 1;
    cout << res << endl;
}