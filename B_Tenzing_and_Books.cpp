#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
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
    long long n, z;
    cin >> n >> z;
    long long a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    long long x = 1;
    int idx1 = -1;
    int idx2 = -1;
    int idx3 = -1;
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= 31; i++)
        {
            if ((z & (1 << i)) == 0 && (a[j] & (1 << i)) != 0)
            {
                flag = 1;
                break;
            }
            x = x * (2 * 1LL);
        }
        if (!flag)
            idx1 = j;
        else
            break;
    }
    x = 1;
    flag = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= 31; i++)
        {
            if ((z & (1 << i)) == 0 && (b[j] & (1 << i)) != 0)
            {
                flag = 1;
                break;
            }
            x = x * (2 * 1LL);
        }
        if (!flag)
            idx2 = j;
        else if (flag == 1)
            break;
    }
    x = 1;
    flag = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= 31; i++)
        {
            if ((z & (1 << i)) == 0 && (c[j] & (1 << i)) != 0)
            {
                flag = 1;
                break;
            }
            x = x * (2 * 1LL);
        }
        if (!flag)
            idx3 = j;
        else
            break;
    }
    vector<int> v(31, 0);
    x = 1;
    for (int i = 0; i < 31; i++)
    {
        if ((z & (1 << i)) != 0)
        {
            v[i]++;
        }
    }
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j <= idx1; j++)
        {
            if (((1 << i) & a[j]) != 0 && ((1 << i) & z) != 0)
            {
                v[i] = max(v[i] - 1, 0);
            }
        }
    }
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j <= idx2; j++)
        {
            if (((1 << i) & b[j]) != 0 && ((1 << i) & z) != 0)
            {
                v[i] = max(v[i] - 1, 0);
            }
        }
    }
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j <= idx3; j++)
        {
            if (((1 << i) & c[j]) != 0 && ((1 << i) & z) != 0)
            {
                v[i] = max(v[i] - 1, 0);
            }
        }
    }
    for (auto it : v)
    {
        if (it > 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}