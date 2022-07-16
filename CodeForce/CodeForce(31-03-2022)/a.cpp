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
        string s;
        cin >> s;
        int flag = 0;
        if (s[0] != 'Y')
        {
            if (s[0] != 'y')
            {
                flag = 1;
            }
        }
        if (s[1] != 'E')
        {
            if (s[1] != 'e')
            {
                flag = 1;
            }
        }
        if (s[2] != 'S')
        {
            if (s[2] != 's')
            {
                flag = 1;
            }
        }

        if (flag == 1)
            cout << "NO" << el;
        else
            cout << "YES" << el;
    }
}