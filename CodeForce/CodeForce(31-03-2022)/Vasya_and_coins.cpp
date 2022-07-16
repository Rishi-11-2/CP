#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int s = 0;
        if (a == 0)
        {
            s = 1;
            cout << s << endl;
            continue;
        }
        else if (b == 0)
        {
            s = a + 1;
            cout << s << endl;
            continue;
        }
        else
        {
            s = a + (b * 2) + 1;
            cout << s << endl;
            continue;
        }
    }
}