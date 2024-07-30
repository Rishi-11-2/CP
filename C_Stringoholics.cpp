#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb(n) push_back(n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define coutyes cout<<"YES"<<endl
#define coutno cout<<"NO"<<endl
#define mp make_pair
#define ff first
#define ss second
#define rep(i, n)  for(int i=0;i<n;i++)
#define vep(i, j, n)  for(int i=j;i<n;i++)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef tree<pair<int, int>, null_type,
        less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;
// order_of_key (k) : Number of items strictly smaller than k.
// find_by_order(k) : K-th element in a set (counting from zero).
typedef long long ll;
typedef long double ld;

ll N = 1000000007;

void init_code() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("Input1.txt", "r", stdin);
    freopen("Output1.txt", "w", stdout);
#endif
}
//2d prefix{
//to cal prefix ->pre[i][j]= v[i][j]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
//to get ans from a,b->c,d ->pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1];
//}

ll powe(ll a, ll n) {

    ll r = 1;
    while (n) {
        if (n % 2) {
            r = ((r % N) * (a % N)) % N;
            n--;
        }
        else {
            a = ((a % N) * (a % N)) % N;
            n = n / 2;
        }
    }
    return r;
}
int M = 100000;
int sieve[100001];

void createSieve() {
    for (int i = 2; i <= M; i++) {
        sieve[i] = 1;
    }
    for (int i = 2; i * i <= M; i++) {
        if (sieve[i] == 1) {
            if (i == 2) {
                for (int j = i * i; j <= M; j += i) {
                    sieve[j] = 2;
                }
            }
            else {
                for (int j = i * i; j <= M; j += 2 * i) {
                    if (sieve[j] == 1) {
                        sieve[j] = i;
                    }
                }
            }
        }
    }
}
struct Hash {
    const long long mod1 = (long long)(1e9 + 7);
    // const long long mod2 = (long long)(1e9 + 1);
    // const long long mod3 = (long long)(1e15 + 5);
    const long long p1 = 1901;
    // const long long p2 = 2003;
    // const long long p3 = 999119999;
    long long *pref1;
    // vector<long long>hash;
    long long *base_pow1;
    // long long *base_pow2;
    // long long *pref2;
    string s;
    long long n;
    Hash(const string &a)
    {
        s = a;
        n = s.length();
        pref1 = (long long*)(malloc((n + 1) * sizeof(long long)));
        // pref2 = (long long*)(malloc((n + 1) * sizeof(long long)));
        base_pow1 = (long long*)(malloc((n + 1) * sizeof(long long)));
        // base_pow2 = (long long*)(malloc((n + 1) * sizeof(long long)));
        base_pow1[0] = 1;
        // base_pow2[0] = 1;
        pref1[0] = 1;
        // pref2[0] = 1;
        for (long long i = 1; i <= n; i++)
        {
            base_pow1[i] = (p1 * base_pow1[i - 1]) % mod1;
            // base_pow2[i] = (p2 * base_pow2[i - 1]) % mod2;
            pref1[i] = ((pref1[i - 1] * p1) % mod1 + s[i - 1] + 997) % mod1;
            // pref2[i] = ((pref2[i - 1] * p2) % mod2 + s[i - 1] + 997) % mod2;
        }
    }

    long long get_hash(int l, int r)
    {
        long long h1 = pref1[r + 1] - (pref1[l] * base_pow1[r - l + 1]) % mod1;
        // long long h2 = pref2[r + 1] - (pref2[l] * base_pow2[r - l + 1]) % mod2;
        if (h1 < 0)
            h1 += mod1;

        // if (h2 < 0)
        //     h2 += mod2;
        // long long h3 = (h1 * p1) % mod3;
        // h3 = (h3 + h2) % mod3;
        return h1;
    }

};

const int mod = (1e9) + 7;
ll lcmModuloM(vector<int> &ar, int n)
{
    gp_hash_table<int, int> max_map;
    for (int i = 0; i < n; i++) {
        int num = ar[i];
        gp_hash_table<int, int> temp;
        while (num > 1) {
            int factor = sieve[num];
            if (factor == 1)factor = num;
            temp[factor]++;
            num /= factor;
        }

        for (auto it : temp) {
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }

    ll ans = 1;

    for (auto it : max_map) {
        ans = (ans * powe(it.first, it.second)) % mod;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int>v;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        Hash h(s);
        int sz = s.size();
        set<int>ss;
        ss.insert(0);
        for (int j = 1; j < s.length(); j++)
        {
            if ((h.get_hash(j, sz - 1) == h.get_hash(0, sz - j - 1)) && (h.get_hash(0, j - 1) == h.get_hash(sz - j, sz - 1)))
            {
                ss.insert(j);
            }
        }
        // for (auto i : ss)cout << i << " "; cout << endl;
        int count = 1;
        int t = 1; t %= sz;
        int minm = 1;

        while (1 && sz != 1)
        {
            // debug("hi");
            if (ss.find(count) != ss.end())
            {
                minm = t;
                break;
            }
            t = t + 1;
            // debug(count,t);
            count = (count + t) % sz;

        }
        // debug(i,minm,mm);
        v.push_back(minm);
    }

    cout << lcmModuloM(v, n) << endl;;

}

int main() {
    init_code();
    createSieve();
    ll t;
    // t = 1;
    cin >> t;
    while (t--) {

        solve();
    }

    return 0;
}