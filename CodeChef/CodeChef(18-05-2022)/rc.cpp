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
        string s[n];
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            if (s[i] == "START38")
            {
                a++;
            }
            if (s[i] == "LTIME108")
            {
                b++;
            }
        }
        cout << a << " " << b << endl;
        ;
    }
}