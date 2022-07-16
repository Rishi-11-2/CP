#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n];
        ll s = 0;
        ll d = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (m < a[i])
            {
                d = (s - a[i]) + (a[i] - m);
                break;
            }
            s = s - a[i];
            m = m - a[i];
        }
        cout << d << endl;
    }
}