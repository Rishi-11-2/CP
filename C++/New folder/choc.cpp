#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int c, x, y;
        cin >> c >> x >> y;
        cout << (c - x) * y << endl;
    }
}