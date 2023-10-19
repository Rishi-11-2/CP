#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
string canF(string a, string b, int n)
{
    string z = "";
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (a[i] == b[i])
            z += a[i];
        else
        {
            // cout << a[i] << " " << b[i] << endl;
            z += a[i];
            z += b[i];
        }
    }
    if (z.length() <= (3 * n))
        return z;
    else if (z.length() > (3 * n))
        return "hi";
}
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
    vector<string> v;
    for (int i = 0; i < 3; i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            string z = canF(v[i], v[j], n);
            // cout << z << endl;
            if (z != "hi")
            {
                reverse(all(z));
                cout << z << endl;
                return;
            }
        }
    }
}