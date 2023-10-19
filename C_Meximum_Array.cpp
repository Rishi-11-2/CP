#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
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
    multiset<long long, greater<long long>> s1;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        s1.insert(arr[i]);
    }
    set<long long> s;
    long long i = 0;
    long long j = 0;
    long long maxm = *s1.begin();
    vector<long long> res;
    while (j < n)
    {
        if (!s.empty() && (s.size() == (maxm + 1)))
        {
            s.erase(all(s));
            res.push_back(maxm + 1);
            if (!s1.empty())
                maxm = *s1.begin();
            else
                break;
        }
        else
        {
            s.insert(arr[j]);
            if (s1.find(arr[j]) != s1.end())
                s1.erase(s1.find(arr[j]));
            j++;
        }
    }
    long long sz = s.size();
    for (long long i = 0; i <= sz; i++)
    {
        if (s.find(i) == s.end())
        {
            res.push_back(i);
            break;
        }
    }

    cout << res.size() << endl;
    for (auto it : res)
        cout << it << " ";
    cout << endl;
}