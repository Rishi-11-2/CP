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
        ll N;
        cin >> n;
        ll a[n];
        int flag = 0;
        int y = 0;
        int h = INT_MAX;
        int j = 0;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            a[i] = (s[i] - '0');
            if (a[0] == 9)
            {
                y = 1;
            }
            if (a[i] == 9)
            {
                flag++;
            }
        }
        if (flag == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << 2;
            }
            cout << el;
        }
        else if (y == 1)
        {
            int b[n];
            int carry = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                b[i] = (1 - a[i]) - carry;
                if (b[i] < 0)
                {
                    b[i] += 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
            }
            for (int i = 0; i < n; i++)
            {
                cout << b[i];
            }
            cout << el;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << 9 - a[i - 1];
            }
            cout << el;
        }
    }
}