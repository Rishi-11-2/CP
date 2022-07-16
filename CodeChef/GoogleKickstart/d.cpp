#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p = 1;
        map<int, vector<int>> m;
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            m[arr[i]].push_back(i + 1);
        }
        for (auto &i : m)
        {
            if (i.second.size() == 1)
            {
                p = 0;
            }
        }
        for (auto &i : m)
        {
            int l = i.second.size();
            reverse(i.second.begin(), i.second.end());
            if (l % 2 != 0)
            {
                swap(i.second[l / 2], i.second[0]);
            }
        }
        if (p != 0)
        {
            for (auto &i : m)
            {
                for (auto &k : i.second)
                {
                    cout << k << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}