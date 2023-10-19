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
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b[i] = arr[i];
    }
    sort(b, b + n);
    int mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == mex)
        {
            mex++;
        }
    }
    int x = mex + 1;
    int st = 0, en = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            st = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == x)
        {
            en = i;
            break;
        }
    }
    if (st == 0 && en == 0)
    {
        if (x > n)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        for (int i = st; i <= en; i++)
        {
            arr[i] = mex;
        }
        sort(arr, arr + n);
        int mex2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mex2)
            {
                mex2++;
            }
        }
        if (mex2 == x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}