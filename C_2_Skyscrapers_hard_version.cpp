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
    long long left[n], right[n];
    stack<long long> st;
    for (long long i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            left[i] = (i + 1) * arr[i];
        else if (!st.empty())
        {
            left[i] = arr[i] * (i - st.top()) + left[st.top()];
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (long long i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            right[i] = arr[i] * (n - i);
        }
        else
        {
            right[i] = right[st.top()] + (st.top() - i) * arr[i];
        }
        st.push(i);
    }
    long long maxm = 0;
    long long idx = 0;
    for (long long i = 0; i < n; i++)
    {
        long long s = left[i] + right[i] - arr[i];
        if (s > maxm)
        {
            maxm = s;
            idx = i;
        }
    }
    // cout << idx << endl;
    long long ans[n];
    long long mn = arr[idx];
    for (long long i = idx; i < n; i++)
    {
        mn = min(mn, arr[i]);
        ans[i] = mn;
    }
    mn = arr[idx];
    for (long long i = idx; i >= 0; i--)
    {
        mn = min(mn, arr[i]);
        ans[i] = mn;
    }
    for (long long i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}