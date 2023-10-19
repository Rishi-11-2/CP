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
    long long n, p;
    cin >> n >> p;
    long long arr[n];
    long long b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = arr[i];
    }
    sort(arr, arr + n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == arr[n - 1])
        {
            idx = i;
            break;
        }
    }
    long long t = p / arr[n - 1];
    if (p % arr[n - 1])
    {
        t++;
    }
    cout << idx + 1 << " " << t << endl;
}