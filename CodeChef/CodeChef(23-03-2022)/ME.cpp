#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int s[n];
        int d[n];
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == d[i])
                y++;
        }
        cout << y << endl;
    }
}