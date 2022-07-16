#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int n = 1;
        string z = " ";
        while (true)
        {
            string y = s.substr(n - 1, 1);
            string s1 = s.substr(n, s.length() - n);
            if (s1.find(y) != string::npos)
            {
                z = s.substr(n, s.length() - n);
            }
            else
            {
                break;
            }
            n++;
            if (n == s.length())
                break;
        }
        if (s.length() == 1)
            z = s;
        cout << z;
    }
}