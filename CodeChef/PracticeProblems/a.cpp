// https://www.codechef.com/submit/COPYPUSH
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
    string s;
    cin >> s;
    int len = s.length();
    while (len > 0)
    {
        if (len % 2 == 0)
        {
            int mid = len / 2;
            if (s.substr(0, mid) != s.substr(mid, len - mid))
            {
                cout << "NO" << el;
                return;
            }
            len /= 2;
        }
        else
            len--;
    }
    cout << "YES" << el;
}