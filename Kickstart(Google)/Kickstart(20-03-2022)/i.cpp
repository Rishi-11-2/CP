#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    int x = 1;
    while (t-- > 0)
    {
        string i;
        cin >> i;
        string p;
        cin >> p;
        int z = 0;
        int w = 0;
        if (p.length() < i.length())
            z = 1;
        if (p.length() == i.length())
            z = 1;
        for (int j = 0; j < i.length(); j++)
        {
            if (p.find(i[j]) != string::npos)
            {
                w += 1;
                p[p.find(i[j])] = ' ';
            }
        }
        if (w < i.length())
            z = 1;
        if (w == i.length())
            z = 0;
        if (z == 1)
            cout << "CASE #" << x++ << ": IMPOSSIBLE" << endl;
        else
            cout << "CASE #" << x++ << ": " << p.length() - w << endl;
    }
}
