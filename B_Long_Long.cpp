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
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int c = 0;
    long long s = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        s += abs(arr[i]);
        if (arr[i] < 0 && flag == 0)
        {
            c++;
            flag = 1;
        }
        else if (arr[i] > 0)
        {
            flag = 0;
        }
    }
    cout << s << " " << c << endl;
}