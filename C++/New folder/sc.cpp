#include <bits/stdc++.h>
using namespace std;
string convertToString(char *a)
{
    string s(a);
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x = 0;
        int n;
        cin >> n;
        char c[n];
        cin >> c;
        string s = convertToString(c);
        sort(s.begin(), s.end());
        for (int i = 0; i < n / 2; i++)
        {
            if (c[n - i - 1] < c[i])
            {
                char a = c[n - 1 - i];
                c[n - 1 - i] = c[i];
                c[i] = a;
            }
            string z = convertToString(c);
            if (s.compare(z) == 0)
            {
                cout << "YES" << endl;
                x = 1;
                break;
            }
        }
        if (x == 0)
            cout << "NO" << endl;
    }
}