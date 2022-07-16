#include <bits/stdc++.h>
using namespace std;
int convert(string a, string b, int m)
{
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        s += abs(a[i] - b[i]);
    }
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        int minM = INT_MAX;
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    minM = min(minM, convert(s[i], s[j], m));
                }
            }
        }
        cout << minM << endl;
    }
}