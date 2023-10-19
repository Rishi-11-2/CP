#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool check(long long n)
{
    vector<long long> v;
    for (int i = 1;; i++)
    {
        long long x = pow(3, i);
        if (x > n)
            break;
        v.push_back(x);
    }
    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    int high = v.size() - 1;
    while (high >= 0)
    {
        if (v[high] - 1 > n)
        {
            high--;
        }
        else
        {
            n -= (v[high] - 1);
        }
    }
    if (n == 0)
        return true;
    else
        return false;
}
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
    long long n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << "Yes" << endl;
        return;
    }
    if (k > n)
    {
        cout << "No" << endl;
        return;
    }
    long long x = 1LL;
    while (x <= n)
    {
        x = x * (3 * 1LL);
        if (x > n)
        {
            x /= (3 * 1LL);
            break;
        }
    }
    n = n - x;
    n -= (k - 1);
    // cout << n << endl;
    if (n == 0)
    {
        cout << "Yes" << endl;
    }
    else if (check(n))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}