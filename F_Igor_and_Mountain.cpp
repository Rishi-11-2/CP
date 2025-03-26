#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
// (data type to be stored, "null_type", comparator, underlying tree, node update policy)
typedef tree < pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;
 
const int mod = 998244353;
 
void solve();
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
int f(int l,int r ,int flag, vector<vector<int>>&prefix)
{
    int s = prefix[r][flag] % mod;
    if (l > 0) {
        s = (s - prefix[l-1][flag]) % mod;
        if(s < 0) s += mod;
    }
    return s;
}
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
 
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
 
    vector<vector<int>> dp_prev(m+1, vector<int>(3, 1));
    vector<vector<int>> prefix(m+1, vector<int>(3, 0));
 
    for (int j = 0; j < m; j++){
        if (grid[0][j] == 'X')
            prefix[j][1] = dp_prev[j][1];
        if (j) {
            prefix[j][1] = (prefix[j][1] + prefix[j-1][1]) % mod;
        }
    }
 
 
    for (int j = 0; j < m; j++){
        int l = max(0, j - d);
        int r = min(m - 1, j + d);
        int res = f(l, r, 1,prefix);
        dp_prev[j][0] = (dp_prev[j][0] - dp_prev[j][1] + f(l, r, 1,prefix)) % mod;
        if(dp_prev[j][0] < 0) dp_prev[j][0] += mod;
    }
 
    for (int j = 0; j < m; j++){
        if (grid[0][j] == 'X')
            prefix[j][0] = dp_prev[j][0];
        if (j){
            prefix[j][0] = (prefix[j][0] + prefix[j-1][0]) % mod;
        }
    }
 
    for (int i = 1; i < n; i++){
        vector<vector<int>> dp_curr(m+1, vector<int>(3, 0));
        vector<vector<int>> nprefix(m+1, vector<int>(3, 0));
        for (int j = 0; j < m; j++){
            int s = sqrt(d * d - 1);
            int l = max(0, j - s);
            int r = min(m - 1, j + s);
            int res = f(l, r, 0,prefix);
            dp_curr[j][0] = res ;
            dp_curr[j][1] = res ;
        }
 
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'X')
                nprefix[j][1] = dp_curr[j][1];
            if (j)
                nprefix[j][1] = (nprefix[j][1] + nprefix[j-1][1]) % mod;
        }
 
        for (int j = 0; j < m; j++){
            int l = max(0, j - d);
            int r = min(m - 1, j + d);
            int res = f(l, r, 1,nprefix);
            dp_curr[j][0] = (res + dp_curr[j][0] - dp_curr[j][1]) % mod;
            if(dp_curr[j][0] < 0) dp_curr[j][0] += mod;
        }
 
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'X')
                nprefix[j][0] = dp_curr[j][0];
            if (j)
                nprefix[j][0] = (nprefix[j][0] + nprefix[j-1][0]) % mod;
        }
        prefix = nprefix;
        dp_prev = dp_curr;
    }
 
    int res = 0;
    for (int j = 0; j < m; j++){
        if (grid[n-1][j] == 'X')
            res = (res + dp_prev[j][0]) % mod;
    }
    cout << res << endl;
}
