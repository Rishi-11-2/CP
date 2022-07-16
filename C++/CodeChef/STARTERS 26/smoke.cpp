#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int s = 0;
        int n;
        int x;
        int y;
        cin >> n >> x >> y;
        if (n / 100)
        {
            s = (n / 100) * x;
            n = n % 100;
        }
        s += (n % 4) * y;
        if (!n % 4)
            s++;

        cout << s << endl;
    }
}