// https://codeforces.com/contest/706/problem/B
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    sort(arr, arr + n);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int index = -1;
        index = upper_bound(arr, arr + n, x) - arr;
        index--;

        cout << index + 1 << el;
    }
}