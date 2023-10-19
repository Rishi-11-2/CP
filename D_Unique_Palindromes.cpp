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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k, vector<int>());
    for (int i = 0; i < k; i++)
    {
        cin >> v[i][0];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> v[i][1];
    }
    int flag = 0;
    for (int i = 0; i < k; i++)
    {
        if (v[i][0] != v[i][1])
            flag = 1;
        if (v[i][0] == v[i][1] && flag == 1)
        {
            cout << "NO" << endl;
            return;
        }
        if (v[i][1] > v[i][0])
        {
            cout << "NO" << endl;
            return;
        }
    }
    
}