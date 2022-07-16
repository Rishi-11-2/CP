#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int l = 0;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        int sC = 0;
        int lC = 0;
        int uC = 0;
        string z = s;
        int nh = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#' or s[i] == '@' or s[i] == '*' or s[i] == '&')
            {
                sC = 1;
            }
            if (s[i] >= 97 and s[i] <= 122)
            {
                lC = 1;
            }
            if (s[i] >= 65 and s[i] <= 90)
            {
                uC = 1;
            }
            if (s[i] >= 49 and s[i] <= 57)
            {
                nh = 1;
            }
        }
        if (sC == 0)
        {
            z += '#';
        }
        if (lC == 0)
        {
            z += 'a';
        }
        if (uC == 0)
        {
            z += 'A';
        }
        if (nh == 0)
        {
            z += '1';
        }
        int k = z.length();
        if (k < 7)
        {
            for (int i = 1; i <= (7 - k); i++)
            {
                z += '1';
            }
        }
        cout << "Case #" << (++l) << ": " << z << endl;
    }
}