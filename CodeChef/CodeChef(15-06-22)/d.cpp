#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        int b[n];
        int h = 1;
        int p = 0;
        for (int i = 0; i < n; i++)
        {

            a[i] = h;
            b[i] = h;
            p++;
            if (p == 5)
            {
                p = 0;
                h++;
            }
        }

        h = 1;
        int s = 0;
        p = 0;
        for (int i = 0; i < n; i++)
        {
            b[i] = h;
            if (i != (k - 1))
            {
                p++;
            }
            else
            {
                b[i] = 0;
                continue;
            }

            if (p == 5)
            {
                p = 0;
                h++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (b[i] != a[i] and i != k - 1)
                s++;
        }
        cout << s << endl;
    }
}