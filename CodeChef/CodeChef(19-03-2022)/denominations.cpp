#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x;
        cin >> x;
        int s = 0;
        s = x / 10;
        x %= 10;
        s += x / 5;
        x %= 5;
        s = (x == 0) ? s : -1;
        cout << s << endl;
    }
}