#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        cin >> n >> x;
        cout << (((2 * n) - x) + 1) << endl;
    }
}