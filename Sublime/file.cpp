#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{  
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n;
        cin >> n;
        int index = 0;
        int mL = 0;
        int cb = 0;
        stack<char> st;
        vector<string> p;
        st.push(s[0]);
        int z = (s[0] - 96);
        if (z == n)
            cout << s[0] << el;
        else if (s.length() == 1)
        {
            cout << s << el;
        }
        else
        {
            int b = 1;
            while (b != s.length())
            {
                z += (s[b] - 96);
                st.push(s[b]);

                while (z > n)
                {

                    z -= (st.top() - 96);
                    st.pop();
                }
                if ((z == n) or (b == (s.length() - 1) and z < n))
                {
                    string x = "";
                    stack<char> dm;
                    while (!st.empty())
                    {//////
                        dm.push(st.top());
                        x = st.top() + x;
                        st.pop();
                    }
                    p.pb(x);
                    index = (x.length() > mL) ? cb : index;
                    cb++;
                    mL = max((int)x.length(), mL);
                    while (!dm.empty())
                    {
                        st.push(dm.top());
                        dm.pop();
                    }
                    z -= (st.top() - 96);
                    st.pop();
                }
                b++;
            }
            string x = "";
            while (!st.empty())
            {
                x = st.top() + x;
                st.pop();
            }
            if (x == "")
            {
                cout << "" << el;
            }
            else
            {
                cout << p[index] << el;
            }
        }
    }
}