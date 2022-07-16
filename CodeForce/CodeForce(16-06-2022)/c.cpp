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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        if (n % 2 == 0)
        {
            s += '1';
            for (int i = 1; i <= (n - 2); i++)
            {
                s += '0';
            }
            s += '1';
        }
        else
        {
            s += '0';
            for (int i = 1; i <= n - 2; i++)
            {
                s += '1';
            }
            s += '0';
        }
        cout << s << endl;
    }
}