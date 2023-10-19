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
    int n;
    cin >> n;
    set<int> s1;
    set<int> s2;
    set<int> s3;
    for (int i = 1; i <= n; i++)
    {
        int x;
        string s;
        cin >> x;
        cin >> s;
        int c = 0;
        if (s[0] == '1' && s[1] == '1')
            s3.insert(x);
        else if (s[0] == '1')
            s1.insert(x);
        else if (s[1] == '1')
            s2.insert(x);
    }
    if (s2.empty() || s1.empty())
    {
        if (s3.empty())
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            cout << *s3.begin() << endl;
            return;
        }
    }
    int xx = *s1.begin() + *s2.begin();
    int yy = INT_MAX;
    if (!s3.empty())
    {
        yy = *s3.begin();
    }
    cout << min(xx, yy) << endl;
}