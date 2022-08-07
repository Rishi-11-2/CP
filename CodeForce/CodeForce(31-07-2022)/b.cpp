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
    int n, H, M;
    cin >> n >> H >> M;
    int minH = INT_MAX;
    int minM = INT_MAX;
    int k = 0;
    int minL = INT_MAX;
    vector<pair<int, int>> v(n + 2);
    vector<pair<int, int>> p(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == H and v[i].second == M)
        {
            cout << 0 << " " << 0 << el;
            return;
        }
        int a = v[i].first - H;
        int b = v[i].second - M;
        if (a < 0)
        {
            a += 24;
            if (b < 0)
            {
                a--;
                b += 60;
            }
        }
        if (a > 0 and b < 0)
        {
            a--;
            b += 60;
        }
        p[i].first = a;
        p[i].second = b;
        if (p[i].first == minH)
        {
            if (p[i].second < minM)
            {
                minM = p[i].second;
                minL = i;
            }
        }
        if (p[i].first < minH)
        {
            minH = p[i].first;
            minL = i;
        }
    }

    cout << minH << " " << p[minL].second << el;
}