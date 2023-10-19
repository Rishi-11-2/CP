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
    map<string, int> mp;
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string x = s;
        reverse(all(s));
        if (mp[s] == 0 && mp[x] == 0)
        {
            c++;
            mp[s] = 1;
            mp[x] = 1;
        }
    }
    cout << c << endl;
}