#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    long long n, x;
    cin >> n >> x;
    queue<long long> q;
    map<long long, int> mp;
    mp[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        long long v = q.front();
        q.pop();
        string s = to_string(v);
        if (s.length() == n)
        {
            cout << mp[v] << endl;
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            long long a = s[i] - '0';
            if (a != 0 && a != 1)
            {
                long long y = v * a;
                if (!mp.count(y))
                {
                    mp[y] = mp[v] + 1;
                    q.push(y);
                }
            }
        }
    }
    cout << -1 << endl;
}