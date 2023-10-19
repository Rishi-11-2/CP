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
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    set<long long> s;
    for (long long i = 1; i <= n; i++)
        s.insert(i);
    if (s.find(arr[0]) != s.end())
        s.erase(arr[0]);
    long long rem = 0;
    int flag = 0;
    for (long long i = 1; i < n - 1; i++)
    {

        if (s.find(arr[i] - arr[i - 1]) != s.end())
        {
            s.erase(arr[i] - arr[i - 1]);
        }
        else
        {
            rem = arr[i] - arr[i - 1];
            flag = 1;
        }
    }
    if (s.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    long long x = *s.begin();
    s.erase(s.begin());
    long long y = -1;
    if (!s.empty())
        y = *s.begin();
    if (flag == 1 && x + y == rem)
    {
        cout << "YES" << endl;
    }
    else if (flag != 1 && ((x + y) == arr[0] || y == -1))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}