#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
bool isCheck(long long arr[], long long n, long long x)
{
    long long curr=arr[0]+x;
    long long c=1;
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i]-curr)>x)
        {
            c++;
            curr=arr[i]+x;
        }
    }
    return (c<=3);
}
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
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long low = 0;
    long long high = 1e9 + 10;
    long long res = high;
    while (low <= high)
    {
        long long mid = (low + high) >> 1;
        if (isCheck(arr, n, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << res << endl;
}