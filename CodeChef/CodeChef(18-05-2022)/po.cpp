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
        int a[4];
        int z = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
            z = max(z, a[i]);
        }
        cout << z << endl;
    }
}