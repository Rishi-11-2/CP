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
        int a[n];
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != 0)
            {
                z = i;
            }
        }
        cout << z << endl;
    }
}