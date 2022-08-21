#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
#define INF INT_MAX
void solve(int t);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    int z = 1;
    while (t--)
    {
        solve(z);
        z++;
    }
    // #ifndef ONLINE_JUDGE
    //     cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    // #endif
}
void solve(int t)
{
    int n;
    cin >> n;
    int arr[n] = {0};
    int b = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < n;)
    {
        if (k % 2 == 0)
        {
            arr[i] = -1;
            b++;
            i += 3;
        }
        else
        {
            arr[i] = 1;
            j++;
            i += 2;
        }
        k++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << "Case #" << t << ": " << b << el;
    return;
}