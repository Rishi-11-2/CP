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
        string s;
        cin >> s;
        int y = 0;
        ht<char, int> a;
        for (int i = 0; i < n; i++)
        {
            if (a.find(s[i]) == a.end())
            {
                a[s[i]] = 1;
                y += 2;
            }
            else
            {
                y += 1;
            }
        }
        cout << y << el;
    }
}