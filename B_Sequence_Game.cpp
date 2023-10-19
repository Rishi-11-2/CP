#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> b;
    b.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
            b.push_back(arr[i]);
        else
        {
            b.push_back(arr[i]);
            b.push_back(arr[i]);
        }
    }
    cout << (int)(b.size()) << endl;
    for (auto it : b)
        cout << it << " ";
    cout << endl;
}