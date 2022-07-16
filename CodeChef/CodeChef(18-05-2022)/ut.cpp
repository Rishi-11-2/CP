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
        int z = 0;
        for (int i = 0; i < (n / 2); i++)
        {
            if (s[i] != s[n - i - 1])
            {
                z++;
            }
        }
        cout << ceil(z / 2.0) << endl;
    }
}