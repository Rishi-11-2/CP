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
        int arr[n];
        map<int, int> m;
        int maxM = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]] += 1;
            maxM = max(maxM, arr[i]);
        }
        int y = 0;
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxM)
            {
                y++;
            }
            int h = 0;
            if (m[arr[i]] > 1)
            {
                h = m[arr[i]] + arr[i] - 1;
            }
            int p = maxM + (y - 1);
            int y = max(h, p);
            f = max(f, y);
        }
        cout << f << endl;
    }
}