#pragma GCC optimize('Ofast')
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        uset<string> h;
        for (int i = 0; i < n; i++)
        {
            string b;
            cin >> b;
            s[i] = b;
            h.insert(s[i]);
        }
        for (auto i : s)
        {
            int p = 0;
            for (int j = 1; j < i.length(); j++)
            {
                string a = i.substr(0, j);
                string b = i.substr(j);
                if (h.find(a) != h.end() and h.find(b) != h.end())
                {
                    cout << 1;
                    p = 1;
                    break;
                }
            }
            if (p == 0)
                cout << 0;
        }
        cout << el;
    }
}