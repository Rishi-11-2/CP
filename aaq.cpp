#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fio ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define rep(i,a,b) for(int i = a ; i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i>=b;i--)
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vll vector<ll> 
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define pb push_back
#define pi pair<int,int> 
const ll mod = 1e9+7;
void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

/* ************ CODE STATRTS HERE  *************/
int pows[100001];
bool done = 0;

long long power10(int n){
    if(!done){
        pows[0] = 1;
        for(int i = 1; i <= 100000; i++)
            pows[i] = (pows[i-1] * 10LL) % mod;
        done = 1;
    }
    return pows[n];
}
long long cntdp[100001][2];
long long cnt(string &r, int n, int tight)
{
    if(tight == 0) return power10(n);
    if(n== 0) return 1;

    if(cntdp[n][tight] != -1) return cntdp[n][tight];
    long long ans= 0; 
    int ub = r[r.length()-n] - '0';
    for(int d = 0; d<= ub; d++){
        ans += cnt(r, n-1, tight&(d == ub))%mod;
    }
    return cntdp[n][tight] =  ans%mod;
}
long long dp[100001][2][10];
long long help(string &r, int n, int tight, int prev){
    if(n == 0){
        return 0;
    }
    if(dp[n][tight][prev] != -1) return dp[n][tight][prev];

    long long ans = 0;
    int ub = tight? r[r.length() - n] - '0': 9;
    for(int dig = 0; dig <= ub; dig++){
        if(dig != prev){
            long long factor = power10(n-1);
            ans += (1ll*dig*factor*cnt(r, n-1,tight&(dig == ub)))%mod;
        }
        ans +=( help(r, n-1, tight&(dig == ub), dig))%mod;
    }
    return dp[n][tight][prev] = ans%mod;
}   

// long long brute(string &l, int n){
//     int prev = -1;
//     long long ans = 0;
//     for(int idx = 0; idx< l.length() ; idx++){
//         if((l[idx] - '0') != prev){
//             long long factor = power10(l.length() - idx - 1);
//             ans += ((l[idx] - '0')*factor)%mod;
//         }
//         prev = l[idx] - '0';
//     }
//     return ans%mod;
// }
int brute(string& L, int nl){
    int prev_dig = 10;
    ll res = 0;
    for(int i = 0; i < L.length(); i++){
        if((L[i] - '0') != prev_dig){
            res = (res + (L[i] - '0') * power10(L.length() - i - 1)) % mod;
        }
        prev_dig = (L[i] - '0');
    }
    return res % mod;
}

void solve()
{
    int nl, nr;
    string l, r;
    cin >> nl>> l;
    cin >> nr >> r; 
    memset(cntdp, -1,sizeof cntdp);
    memset(dp, -1, sizeof(dp));
    long long val = help(r, nr, 1, -1);
    memset(dp, -1, sizeof dp);
    memset(cntdp, -1,sizeof cntdp);
    long long val2 = help(l, nl, 1, -1);
    cout <<  (val  + (mod - val2) + brute(l, nl)) % mod<< endl; 
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// 6005-5105
// 900