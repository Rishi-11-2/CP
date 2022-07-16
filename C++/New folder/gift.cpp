#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        int z[n];
        int maxS = INT_MIN;
        int s = 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> z[i];
            maxS = max(maxS, z[i]);
            s += z[i];
            index = i;
        }
        s = s - maxS + (ceil(maxS / 2));
        if (s < k)
        {
            cout << n << endl;
        }
        else
        {
            int p = n;
            for (int i = 0; i < n; i++)
            {
                if (i != index)
                {
                    s -= z[i];
                    p--;
                    if (s < k)
                    {
                        break;
                    }
                }
            }
            cout << p << endl;
        }
    }
}