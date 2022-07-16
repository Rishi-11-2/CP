#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int z = 0;
        int n, m;
        cin >> n >> m;
        int s, t;
        cin >> s >> t;
        int s1=s;
        int a[n];
        int p[m][m];
        for (int i = 0; i < m; i++)
        {
            cin >> p[i][i] >> p[i + 1][i];
            if (p[i][i] == s1)
            {
                if(p[i+1][i]==t)
                z++;
            }
           else if (p[i + 1][i] == s1)
            {
                t++;
                s1 = p[i][i];
            }
        }
    }