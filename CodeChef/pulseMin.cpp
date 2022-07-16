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
        int a[n];
        int s = 0;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (i == 0)
            {
                s += abs(a[i]);
            }
            if (i % 2 == 0 && i != 0)
            {
                s += abs(a[i]);
            }
            if (i % 2 != 0 && i != 0)
            {
                s -= abs(a[i]);
            }
            m = s;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s = 0;
                swap(a[i], a[j]);
                for (int k = 0; k < n; k++)
                {

                    if (k == 0)
                    {
                        s += abs(a[k]);
                    }
                    if (k % 2 == 0 && k != 0)
                    {
                        s += abs(a[k]);
                    }
                    if (k % 2 != 0 && k != 0)
                    {
                        s -= abs(a[k]);
                    }
                }
                m = max(m, s);
            }
        }

        cout << m << endl;
    }
}