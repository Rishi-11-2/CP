#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
bool contains(set<int> s1, set<int> s2)
{
    for (auto it : s2)
    {
        if (s1.find(it) == s1.end())
            return false;
    }
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> v;
    vector<int> arr;
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        arr.push_back(p);
        int x;
        cin >> x;
        set<int> a;
        b.push_back(x);
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            a.insert(y);
        }
        v.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (b[i] > b[j])
                continue;
            if (arr[i] >= arr[j])
            {
                if (contains(v[j], v[i]))
                {
                    if (arr[i] > arr[j] || v[j].size() > v[i].size())
                    {
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}