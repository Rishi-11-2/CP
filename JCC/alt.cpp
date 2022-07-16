#include <bits/stdc++.h>
using namespace std;
int found(char c, char ch[], int i, string s)
{
    for (int j = i + 1; j < s.length(); j++)
    {
        if (ch[i] == c)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char c[s.length()];
        int z = 0;
        int h = 0;
        int a1 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            c[i] = s[i];
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (c[i] == '#')
            {
                if (h == 1)
                {
                    int a = found('$', c, i, s);
                    swap(c[i], c[a]);
                    for (int i = 0; i < s.length(); i++)
                    {
                        cout << c[i] << " ";
                    }
                    cout << endl;
                    a1++;
                    h = 0;
                    continue;
                }
                h = 1;
            }
            if (c[i] == '$' and z != 1)
            {
                if (z == 1)
                {
                    int a = found('#', c, i, s);
                    swap(c[i], c[a]);
                    for (int i = 0; i < s.length(); i++)
                    {
                        cout << c[i] << " ";
                    }
                    cout << endl;
                    a1++;
                    z = 0;
                    continue;
                }

                z = 1;
            }
        }
        cout << a1 << endl;
    }
}