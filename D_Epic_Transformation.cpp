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
    int arr[n];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    priority_queue<int> pq;
    for (auto it : m)
        pq.push(it.second);
    while (pq.size() > 1)
    {
        auto i = pq.top();
        pq.pop();
        auto j = pq.top();
        pq.pop();
        i--;
        j--;
        if (i > 0)
            pq.push(i);
        if (j > 0)
            pq.push(j);
    }
    if (pq.empty())
        cout << 0 << endl;
    else
        cout << pq.top() << endl;
}