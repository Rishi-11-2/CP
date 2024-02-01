#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
// ---------------------------------power---------------------------------------

ll bin(ll a, ll b){ if(b == 0){return 1;} else{ if(b%2 == 0){return (bin(a,b/2)*bin(a,b/2));} else{return (bin(a,b/2)*bin(a,b/2)*a);} } } 
ll bpm(ll  a,ll  b, ll  m) { a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a %m; a = a * a % m; b >>= 1; } return res; }
ll modInverse(ll n,int p){return bpm(n, p - 2, p);}
// return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;

//-----------------------start your code----------------------------------------

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll m = (1e9 + 7);
    ll m2 = modInverse(2, m);

    ll ans = n;
    ll prev = n;
    ll j = n+1;

    for(ll i = 2; i*i <= n; i++){
        j = i+1;
        ll x = (n/i);
        ll y = (x*i);
        ans = (ans + y)%m;
        ll sum = (((prev - x)%m)*((x + prev + 1)%m))%m;
        sum = (sum * (i-1))%m;
        sum = (sum * m2)%m;
        ans = (ans + sum)%m;
        prev = x;
    }
    for(ll i = j; i <= prev; i++){
        ll x = (n/i);
        ll y = (x*i);
        ans = (ans + y)%m;
    }
    cout << ans << "\n";
}