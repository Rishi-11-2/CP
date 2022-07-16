#include <bits/stdc++.h>
using namespace std;
int convert(vector<int> a)
{
    int n = 0;
    for (auto it : a)
    {
        n = (n * 10) + (it);
    }
    int k = 0;
    while (n > 0)
    {
        k = (k * 10) + (n % 10);
        n /= 10;
    }
}
int main()
{
    int t = 0;
    cin >> t;
    int x = 0;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int k = n;
        int z1 = 0;
        int z = 0;
        while (k > 0)
        {
            z++;
            z1 = (z1 * 10) + (k % 10);
            k /= 10;
        }
        k = n;
        vector<int> a;
        for (int i = 0; i < z; i++)
        {
            a.push_back(z1 % 10);
            z1 /= 10;
            cout << a[i];
        }
        int s = INT_MAX;
        for (int i = 1; i <= 9; i++)
        {
            a.insert(a.begin(), i);
            int y = convert(a);
            if (y % 9 == 0)
                s = min(s, y);
            a.erase(a.begin());
            a.push_back(i);
            y = convert(a);
            if (y % 9 == 0)
                s = min(s, y);
            a.erase(a.end());
        }
        cout << "Case #" << x++ << ": " << s;
    }
}