
#include <bits/stdc++.h>

using namespace std;

const int N = 200000;

int main()
{
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        string s;
        cin >> s;
        int maxSortedPref = 0;
        int minNotSortedPref = 0;
        int bal = 0;
        bool good = true;

        for (auto c : s)
        {
            if (c == '+')
            {
                ++bal;
            }
            else if (c == '-')
            {
                --bal;
                maxSortedPref = min(maxSortedPref, bal);
                if (bal < minNotSortedPref)
                    minNotSortedPref = 0;
            }
            else if (c == '1')
            {
                maxSortedPref = max(maxSortedPref, bal);
            }
            else
            {
                if (bal <= 1)
                {
                    good = false;
                    break;
                }
                if (minNotSortedPref == 0 || minNotSortedPref > bal)
                    minNotSortedPref = bal;
            }
            if (minNotSortedPref <= maxSortedPref && minNotSortedPref != 0)
            {
                good = false;
                break;
            }
        }

        if (good)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}