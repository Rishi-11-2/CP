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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k = 0;
        int p = n;
        while (n > 0)
        {
            int y;
            cin >> y;
            string s;
            cin >> s;
            for (int i = 0; i < y; i++)
            {
                if (s[i] == 'D')
                {
                    if (a[k] == 9)
                    {
                        a[k] = 0;
                    }
                    else
                    {
                        a[k]++;
                    }
                }
                if (s[i] == 'U')
                {
                    if (a[k] == 0)
                    {
                        a[k] = 9;
                    }
                    else
                    {
                        a[k]--;
                    }
                }
            }
            k++;
            n--;
        }
        for (int i = 0; i < p; i++)
        {
            cout << a[i] << " ";
        }
        cout << el;
    }
}