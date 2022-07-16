#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        char c[n];
        cin >> c;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == c[i + 1])
            {
                i++;
                z++;
            }
            else
            {
                z++;
            }
        }
        cout << z << endl;
    }
}