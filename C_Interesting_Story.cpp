#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> xx(6);
    vector<string> neutral;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        vector<int> count(6, 0);
        int s = 0;
        for (auto it : x)
        {
            count[it - 'a']++;
            s++;
        }
        int flag = 0;
        for (int i = 0; i < 6; i++)
        {
            if (count[i] > (s - count[i]))
            {
                flag = 1;
                xx[i].push_back(x);
                break;
            }
        }
        if (flag == 0)
            neutral.push_back(x);
    }
    for (int i = 0; i < 6; i++)
    {
        vector<int> count(6, 0);
        int sum = 0;
        for (auto it : xx[i])
        {
            for (auto c : it)
            {
                count[c - 'a']++;
                sum++;
            }
        }
        for (auto it : neutral)
        {
            int csum = sum;
            auto countM = count;
            for (auto c : it)
            {
                countM[c - 'a']++;
                csum++;
            }
        }
    }
}