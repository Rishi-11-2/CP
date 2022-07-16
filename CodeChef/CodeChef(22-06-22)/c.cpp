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
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        int flag = 0;
        if (((((abs(y2 - y1)) == 4))) and ((x2 == x1) or (abs(x2 - x1) == 2)))
        {
            cout << "YES" << el;
        }
        else if (((((abs(x2 - x1)) == 4))) and ((y2 == y1) or (abs(y2 - y1) == 2)))
        {
            cout << "YES" << el;
        }
        else if (((((abs(x2 - x1)) == 4))) and ((y2 == y1) or (abs(y2 - y1) == 0)))
        {
            cout << "YES" << el;
        }
        else if (((((abs(x2 - x1)) == 0))) and ((y2 == y1) or (abs(y2 - y1) == 4)))
        {
            cout << "YES" << el;
        }
        else if (((((abs(x2 - x1)) == 2))) and ((y2 == y1)))
        {
            cout << "YES" << el;
        }
        else if (((((abs(y2 - y1)) == 2))) and ((x2 == x1)))
        {
            cout << "YES" << el;
        }
        else if (((abs(x2 - x1)) == 2) and (((abs(y2 - y1)) == 4)))
        {
            cout << "YES" << el;
        }
        else if (((abs(x2 - x1)) == 1) and (((abs(y2 - y1)) == 1)))
        {
            cout << "YES" << el;
        }

        else if (((abs(y2 - y1)) == 2) and (((abs(x2 - x1)) == 4)))
        {
            cout << "YES" << el;
        }
        else if (((abs(y2 - y1)) == 3) and (((abs(x2 - x1)) == 3)))
        {
            cout << "YES" << el;
        }
        else if (((abs(y2 - y1)) == 1) and (((abs(x2 - x1)) == 3)))
        {
            cout << "YES" << el;
        }
        else if (((abs(y2 - y1)) == 3) and (((abs(x2 - x1)) == 1)))
        {
            cout << "YES" << el;
        }
        else
        {
            cout << "NO" << el;
        }
    }
}