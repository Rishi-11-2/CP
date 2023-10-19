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
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxm = max(maxm, arr[i]);
        mp[arr[i]]++;
    }
    int x = maxm - arr[0] + 1;
    if (x == 1 && mp[maxm] == 1)
        x = 0;
    cout << x << endl;
}