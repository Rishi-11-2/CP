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
        int k;
        cin >> k;
        int z = 1;
        string s = to_string(k);
        size_t f1 = s.find('5');
        size_t f2 = s.find('0');
        cout << f1 << endl;
        if (f1 == string::npos and f2 == string::npos)
        {
            z = 0;
        }
        if (k == 0)
        {
            z = 0;
        }
        if (z == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}