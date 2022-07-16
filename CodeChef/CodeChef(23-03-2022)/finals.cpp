#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        int x, y, d;
        cin >> x >> y >> d;
        if (abs(x - y) <= d)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}