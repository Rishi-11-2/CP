#include <bits/stdc++.h> //TLE
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int y = a[i] + a[i + 1];
            s = max(s, y);
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = n; j >= i; j--)
            {
                reverse(a + i, a + j);
                for (int k = 0; k < n - 1; k++)
                {
                    int y = a[k] + a[k + 1];
                    s = max(s, y);
                }
                reverse(a + i, a + j);
            }
            for (int j = 0; j <= i; j++)
            {
                reverse(a + j, a + i);
                for (int k = 0; k < n - 1; k++)
                {
                    int y = a[k] + a[k + 1];
                    s = max(s, y);
                }
                reverse(a + j, a + i);
            }
        }
        cout << s << endl;
    }
}