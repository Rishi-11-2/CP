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
        vector<int> a(n);
        int count_Odd = 0;
        int count_Even = 0;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            cin >> k;
            if (k % 2 == 0)
            {
                count_Even++;
            }
            else
            {
                count_Odd++;
            }
            a.push_back(k);
        }
        if (count_Even == 0 or count_Odd == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (count_Odd % 2 == 0)
            {
                cout << count_Odd / 2 << endl;
            }
            else
            {
                cout << n - 1 << endl;
            }
        }
    }
}