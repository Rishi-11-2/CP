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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            int low = i;
            int high = j;
            while (low <= high)
            {
                swap(a[low], a[high]);
                low++;
                high--;
            }
            // for (auto &it : a)
            //     cout << it << " ";
            // cout << endl;
            v.push_back(a);
            low = i;
            high = j;
            while (low <= high)
            {
                swap(a[low], a[high]);
                low++;
                high--;
            }
        }
    }
    sort(all(v));
    for (auto &it : v[k - 1])
    {
        cout << it << " ";
    }
    cout << endl;
}