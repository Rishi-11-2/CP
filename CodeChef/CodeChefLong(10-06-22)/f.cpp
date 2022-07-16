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
        string z;
        cin >> z;
        int d[n];
        int c[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = abs(z[i] - 'a');
            c[i] = abs(s[i] - 'a');
        }
        unordered_set<int> hl;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if ((hl.find(d[i]) == hl.end()) and (c[i] != d[i]))
            {
                if (c[i] != 0 or d[i] != 0)
                {
                    hl.insert(d[i]);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}