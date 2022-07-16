#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        char a[m][n];
        for (int i = 0; i < n; i++)
        {
            char c[m];
            cin >> c;
            for (int j = 0; j < m; j++)
            {
                a[i][j] = c[j];
            }
        }
    }
}