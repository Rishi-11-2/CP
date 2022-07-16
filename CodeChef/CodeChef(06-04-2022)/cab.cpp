#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
        {
            cout << "FIRST" << endl;
        }
        if (x > y)
        {
            cout << "SECOND" << endl;
        }
        if (x == y)
        {
            cout << "ANY" << endl;
        }
    }
}