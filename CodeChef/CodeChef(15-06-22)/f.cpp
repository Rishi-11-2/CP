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
        int n, x;
        cin >> n >> x;
        if (x == 1 and n == x)
        {
            cout << 'z' << el;
        }
        else if (x == n)
        {
            cout << -1 << endl;
        }
        else
        {
            if (n % 2 == 0 and (x > (n / 2)))
            {
                cout << -1 << endl;
            }
            else if (n % 2 == 1 and (x > ((n / 2) + 1)))
            {
                cout << -1 << endl;
            }
            else
            {
                string s = "";
                for (int i = 1; i < x; i++)
                {
                    char a = (char)(96 + i);
                    s += a;
                }
                string v = s;
                reverse(v.begin(), v.end());
                char b = (char)(96 + x);
                for (int i = 1; i <= (n - (2 * (x - 1))); i++)
                {
                    s += b;
                }
                s += v;
                cout << s << endl;
            }
        }
    }
}