#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    int x = 0;
    while (t-- > 0)
    {
        int k = 1;
        bool isAlice = 0;
        bool isBob = 0;
        int n;
        cin >> n;
        vector<int> a;
        int minS = 0;
        int z1 = 0;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            int u;
            cin >> u;
            a.push_back(u);
            if (a[i] < n)
            {
                z1++;
            }
            if (a[i] < minS)
            {
                minS = a[i];
                index = 1;
            }
        }
        if (minS < n)
        {
            if (z1 == n)
            {
                isBob = 1;
            }
            else
            {
                // a.erase(index);
                for (int i = 0; i < n; i++)
                {
                }
            }

            isAlice = 1;
        }
        while (!isAlice && !isBob)
        {
            int h = (a.begin() - a.end());
            a.clear();
            int x = 1;
            int g = minS;
            int p = 0;
            int l = 1;
            while (g-- > 0)
            {
                a[p] += x;
                minS = min(a[p], minS);
                l++;
                p++;
                if (l == h)
                {
                    x++;
                    p = 0;
                    l = 1;
                }
            }
            if (minS < n)
            {
                if (k % 2 == 0)
                    isBob = 1;
                else
                    isAlice = 1;
            }
        }
        if (isAlice == 1)
        {
            cout << "ALICE" << endl;
        }
        if (isBob == 1)
        {
            cout << "BOB" << endl;
        }
    }
}