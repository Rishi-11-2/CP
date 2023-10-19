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
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }
    int startF = -1;
    int endF = -1;
    vector<int> start(3, 0);
    vector<int> end(3, 0);
    int s = 0;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        auto it = v[i];
        if (startF == -1)
        {
            start = v[i];
            s += it[2];
            startF = 1;
        }
        else if (endF == -1)
        {
            if (it[0] == start[0] && it[1] == start[1])
            {
                if (it[2] < start[2])
                {
                    s -= start[2];
                    s += it[2];
                    start = it;
                }
            }
            else if (it[0] < start[0] && it[1] >= start[1])
            {
                s -= start[2];
                s += it[2];
                start = it;
            }
            else if ()
        }
    }
}