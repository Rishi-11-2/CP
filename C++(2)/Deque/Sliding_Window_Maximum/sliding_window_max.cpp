#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }
    multiset<int, greater<int>> s;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for (int i = k; i < n; i++)
    {
        // lower bound removes the first instance of the element which is there in set.
        s.erase(s.lower_bound(a[i - k])); // so that only those elements which are part of the window are there in multiset
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}