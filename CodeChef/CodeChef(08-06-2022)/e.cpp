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
        int h = 0;
        if (s[0] == '1')
        {
            h++;
        }
        if (s[n - 2] == '0')
        {
            h++;
        }
        int flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1' and s[0] == '0')
            {
                if (flag == 0)
                {
                    h += 1;
                }
                flag = 1;
            }
        }
        cout << h << endl;
    }
}