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
        string s;
        cin >> s;
        int c = 0;
        char h[s.length()];
        int y = 0;
        int alt = 0;
        int u = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' and y == 0)
            {
                h[i] = '0';
                y = 1;
                u = 1;
                continue;
            }
            h[i] = s[i];
            y = 0;
        }
        if (u == 1)
        {
            alt++;
            u = 0;
        }
        u = 0;
        while (true)
        {
            y = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (h[i] == '1' and y == 0)
                {
                    h[i] = '0';
                    y = 1;
                    u = 1;
                    continue;
                }
                y = 0;
            }
            if (u == 1)
            {
                u = 0;
                alt++;
            }
            if (u == 0)
            {
                break;
            }
        }
        cout << alt << endl;
    }
}