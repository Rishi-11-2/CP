#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int s = (n / 6) * x;
        if (n % 6 != 0)
        {
            s += (x * 1);
        }
        cout << s << endl;
    }
}
