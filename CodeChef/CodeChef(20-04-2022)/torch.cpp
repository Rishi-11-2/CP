#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k == 1 and n == 0)
        {
            cout << "On" << endl;
        }
        if (k == 1 and n != 0)
        {
            if (n % 4 == 0)
            {
                cout << "On" << endl;
            }
            else
            {
                cout << "Ambiguous" << endl;
            }
        }
        if (k == 0)
        {
            n = n % 4;
            if (n == 0)
            {
                cout << "Off" << endl;
            }
            else
            {
                cout << "On" << endl;
            }
        }
    }
}