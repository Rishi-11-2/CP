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
    set<char> st;
    st.insert('A');
    st.insert('C');
    st.insert('B');
    for (int i = 0; i < n; i++)
    {
        if (st.find(s[i]) != st.end())
            st.erase(s[i]);
        if (st.empty())
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n << endl;
}