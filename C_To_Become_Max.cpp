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
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    function<int(long long)> check = [&](long long mid) -> int
    {
        int flag = 0;
        for (long long i = 0; i < n; i++)
        {
            // cout << "hi" << endl;
            vector<long long> min_n(n, 0);
            long long need = 0;
            min_n[i] = mid;
            for (long long j = i; j < n; j++)
            {
                if (min_n[j] <= arr[j])
                    break;

                if (j + 1 >= n)
                {
                    need = k + 1;
                    break;
                }

                need += (min_n[j] - arr[j]);
                min_n[j + 1] = max(0LL, min_n[j] - 1);
            }
            if (need <= k)
            {
                flag = 1;
            }
        }
        return flag;
    };
    long long low = 0;
    long long high = *max_element(arr, arr + n) + k;
    long long res = 0;
    // cout << check(3) << endl;
    // cout << high << endl;
    while (low <= high)
    {
        long long mid = (high + low) / 2;
        // cout << mid << endl;
        if (check(mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << endl;
}