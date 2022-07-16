#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x, k;
        cin >> n >> x >> k;
        if ((x / k) > n)
        {
            cout << n << endl;
        }
        else
        {
            cout << (x / k) << endl;
        }
    }
}