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
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    vector<long long> v;
    long long idx = 1;
    v.push_back(arr[0]);
    int j = 0;
    for (long long i = 1; i < n; i++)
    {
        idx = i;
        if (abs(arr[i] - arr[i - 1]) == 1)
        {
            v.push_back(arr[i]);
        }
        else
        {
            long long xx = arr[i - 1];
            long long yy = arr[i];
            long long diff = 1;
            if (xx > yy)
                diff = -1;
            xx += diff;
            // yy -= diff;
            for (long long k = xx; k != yy; k += diff)
            {
                v.push_back(k);
            }
            v.push_back(arr[i]);
        }
    }
    // if (idx == n - 1)
    idx++;
    for (long long i = idx; i < n; i++)
        v.push_back(arr[i]);
    for (auto &it : v)
        cout << it << " ";
    cout << endl;
}