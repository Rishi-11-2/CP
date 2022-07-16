#include <bits/stdc++.h>
using namespace std;
bool check(int b[], int i1, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (b[i] == i1)
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        int b[m];
        int c[n / 2 + 1];
        int t = 1;
        int t1 = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!check(b, i, m))
            {
                if (t)
                {
                    cout << i << " ";
                    t = 0;
                }
                else
                {

                    c[t1++] = i;
                    t = 1;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < t1; i++)
        {
            cout << c[i] << " ";
        }
    }
}