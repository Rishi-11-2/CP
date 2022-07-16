#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t1;
    cin >> t1;
    while (t1--)
    {
        string s;
        cin >> s;
        int t = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                i += 1;
                if (i != s.length() - 2)
                {
                    if (s[i] == s[i + 2])
                    {
                        t += 1;
                        i += 2;
                    }
                }
                continue;
            }
            if (s[i] != s[i + 1])
            {
                if (i != s.length() - 2)
                {
                    if (s[i] != s[i + 2])
                    {
                        t += 2;
                        i += 1;
                    }
                    else
                    {
                        t += 1;
                        i += 2;
                    }
                }
                else
                {
                    t += 1;
                }
            }
        }
        cout << t << endl;
    }
}