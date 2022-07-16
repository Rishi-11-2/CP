#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int p = (n * 50);
        int l = ((0.2) * p) + ((0.2) * p) + (0.3 * p);
        cout << (p - l) << endl;
    }
}