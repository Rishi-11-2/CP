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
    // i want to die
    cin >> n;
    int arr[n];
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    if (n > 2)
    {
        arr[0] = 2;
    }
    else
    {
        arr[0] = n;
    }
    arr[n / 2] = 1;
    if (n >= 3)
        arr[n - 1] = 3;
    s.erase(1);
    s.erase(2);
    s.erase(3);
    for (int i = 1; i < n - 1; i++)
    {
        if (i != (n / 2))
        {
            arr[i] = *s.begin();
            s.erase(*s.begin());
        }
    }
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
}