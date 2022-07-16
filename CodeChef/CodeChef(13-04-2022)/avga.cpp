#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;

        cin >> n >> x;

        if (n == 1)
        {
            cout << x << endl;
            break;
        }
        vector<int> z;
        int prev = (x - 1);
        int next = x + 1;
        int c = 0;
        int r = 0;
        while (c < n - 1)
        {
            c += 2;
            r = r + next + prev;
            z.push_back(prev);
            z.push_back(next);
            prev--;
            next++;
        }
        if (n % 2 != 0)
        {
            int y = (n * x) - (r);
            z.push_back(y);
        }

        for (auto it : z)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}