ll expo(ll a, ll b, ll mod) {
    ll res = 1; 
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1;
    } 
    return res;
}
ll mod_add(ll a, ll b, ll m) {
    a = a % m; 
    b = b % m; 
    return (((a + b) % m) + m) % m;
}
ll mminvprime(ll a, ll b) {
    return expo(a, b - 2, b);
}
ll combination1(ll n, ll r, ll m, vector<ll>& fact, vector<ll>& ifact){
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);
}
void solve(){
    int n = 10;
    vector<ll> fact(n + 1);
    vector<ll> ifact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = mod_mul(fact[i - 1], i, MOD);
        ifact[i] = mminvprime(fact[i], MOD);
    }
    ifact[n] = mminvprime(fact[n], MOD);
    for(int i = n - 1; i >= 0; i--){
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }
    
    cout << combination1(8, 6, MOD, fact, ifact) << endl;
}