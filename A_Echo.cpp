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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string z = "";
    for (int i = 0; i < n; i++)
    {
        z += s[i];
        z += s[i];
    }
    cout << z << endl;
}