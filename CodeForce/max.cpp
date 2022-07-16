#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int l, r, a;
        cin >> l >> r >> a;
        int maxS = INT_MIN;
        for (int i = l; i <= r; i++)
        {
            int f = (int)(floor(i / a)) + (i % a);
            maxS = max(maxS, f);
        }
        cout << maxS << endl;
    }
}