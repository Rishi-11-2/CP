#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        t = s;
        sort(t.begin(), t.end());
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] > s[n - i - 1])
            {
                swap(s[i], s[n - i - 1]);
            }
        }
        if (s == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}