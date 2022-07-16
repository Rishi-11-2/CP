// wrong coming
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
        n++;
        int k = n;
        while (true)
        {
            int s = 0;
            while (k > 0)
            {
                s += (k % 10);
                k /= 10;
            }
            if (s % 2 != 0)
            {
                break;
            }
            else
            {
                n++;
                k = n;
            }
        }
        cout << n << endl;
    }
}