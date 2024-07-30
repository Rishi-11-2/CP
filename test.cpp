#if __has_include("pch.hpp")
#include "pch.hpp"
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//ld rand(ld a, ld b) {uniform_real_distribution<ld> uni(a, b); return uni(mt_rand);}
//const ld PI=3.141592653589793238462643383279;
const int mxN=3e5+1;
const int mod=998244353;
const int mxlogN=19;
const ll inf=2e18;
const int iinf=2e9;
const int K=450;
int a[mxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << "1\n";
    cout << "2000\n";
    for(int i=0; i<2000; i++) cout << i/1000-100+(int)(1e9) << " \n"[i+1==2000];
}
