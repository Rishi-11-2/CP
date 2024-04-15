#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Macros
#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//IO functions

void inp(vi& a)
{
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
}

void inp(vll& a)
{
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
}

ostream& operator << (ostream& s, pi& a)
{
    return s << a.fi << " " << a.se;
}

ostream& operator << (ostream& s, pll& a)
{
    return s << a.fi << " " << a.se;
}

ostream& operator << (ostream& s, vi& a)
{
    for(int i : a)
        s << i << " ";
    return s;
}

ostream& operator << (ostream& s, vll& a)
{
    for(ll i : a)
        s << i << " ";
    return s;
}

void yes(bool b)
{
    if(b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

//EXTRA FUNCTIONS*******************************************************

struct node
{
    node* left;
    node* right;
    int cnt;
    node()
    {
        left = NULL;
        right = NULL;
        cnt = 0;
    }
};

struct tri
{
    node* head;
    tri()
    {
        head = new node();
    }

    void add(int i)
    {
        node* cur = head;
        cur->cnt++;
        for(int j = 29; j >= 0; j--)
        {
            if((i>>j)&1)
            {
                if(cur->right == NULL)
                    cur->right = new node();
                cur = cur->right;
            }
            else
            {
                if(cur->left == NULL)
                    cur->left = new node();
                cur = cur->left;
            }
            cur->cnt++;
        }
    }

    int check(int pre, int l)
    {
        node* cur = head;
        for(int i = 29; i >= l; i--)
        {
            if((pre>>i)&1)
                cur = cur->right;
            else
                cur = cur->left;
            if(cur == NULL)
                return 0;
        }
        return cur->cnt;
    }
};


const int MOD = 998244353;

struct mint 
{
    int val;
    mint(ll v = 0)
    {
        if(abs(v) < MOD)
            val = v;
        else
            val = v%MOD;
        if(val < 0)
            val += MOD;
    }
};

mint operator+(const mint& a, const mint& b)
{
    int res = a.val + b.val;
    if(res >= MOD)
        return res-MOD;
    else
        return res;
}
mint operator-(const mint& a, const mint& b)
{
    int res = a.val - b.val;
    if(res < 0)
        return res+MOD;
    else
        return res;
}
mint operator*(const mint& a, const mint& b)
{
    ll res = (ll)a.val * (ll)b.val;
    if(res >= MOD)
        return res%MOD;
    else
        return res;
}
mint operator^(const mint& a, ll b)
{
    ll res = 1;
    ll prod = a.val;
    while(b > 0)
    {
        if(b&1)
            res = (res*prod)%MOD;
        prod = (prod*prod)%MOD;
        b >>= 1;
    }
    return res;
}
mint operator/(const mint& a, const mint& b)
{
    return a*(b^(MOD-2));
}

void operator+=(mint& a, const mint& b)
{
    a = a+b;
}
void operator-(mint& a)
{
    a = 0-a;
}
void operator-=(mint& a, const mint& b)
{
    a = a-b;
}
void operator*=(mint& a, const mint& b)
{
    a = a*b;
}
void operator^=(mint& a, ll b)
{
    a = a^b;
}
void operator/=(mint& a, const mint& b)
{
    a = a/b;
}

bool operator==(const mint& a, const mint& b)
{
    return a.val == b.val;
}

ostream& operator << (ostream& s, mint a)
{
    return s << a.val;
}

//COMBINATORICS AND FACTORIAL

vector<mint> fact;
vector<mint> ifact;

void cfact(int n)
{
    fact.pb(1);
    ifact.pb(1);
    for(int i = 1; i <= n; i++)
    {
        fact.pb(fact.back()*i);
        ifact.pb(fact.back()^(MOD-2));
    }
}

mint comb(int n, int r)
{
    return fact[n] * ifact[n-r] * ifact[r];
}
//END OF EXTRA FUNCTIONS************************************************

//Write code here


void run(int test)
{
    int n; cin >> n;  vi a(n); inp(a);
    tri t; 
    for(int i: a)
        t.add(i);
    
    mint ans = 0;
    for(int i = 0; i < n; i++)
    {

        int one = 0;
        for(int j = 29; j >= 0; j--)
        {
            int pre = a[i];
            pre ^= (1 << j);
            mint cnt = t.check(pre, j);
            int c = (a[i]>>j)&1;
            mint op = one+1;
            if(c == 0)
                op += (one&1);
            else
                op += 1-(one&1);
            ans += op*cnt;
            one += c;
        }
        mint op = one+1;
        mint cnt = t.check(a[i], 0);

        ans += op*cnt;
    }
    mint ways = n;
    ans /= (ways*ways);
    cout << ans << endl;
}   

//Main function

int main()
{
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1; 
    cin >> t;
    for(int i = 1; i <= t; i++)
        run(i);
    return 0;
}