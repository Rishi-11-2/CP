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
#define INF INT_MAX
void solve(int t);
bool isPal(string s, int x, int y)
{
    int low = x;
    int high = y;
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    int z = 1;
    while (t--)
    {
        solve(z++);
    }
}
void solve(int t)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (isPal(s, 0, i) == true)
        {
            index = i;
            int len = index + 1;
            if (n % len == 0)
            {
                break;
            }
        }
    }
    if (s[0] == s[1])
        index = 0;
    string z = s.substr(0, index + 1);

    cout << "Case #" << t << ": " << z << el;
}
