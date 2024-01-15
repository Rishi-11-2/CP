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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
        vector<long long> v;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long p=1;
    v.push_back(1);
    long long i;
    for(i=1;i<=20;i++){
        p = p*2;
        v.push_back(p);
    }

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
     long long l,r;
        cin>>l>>r;
    long long c=0;
        long long maxi;
        long long a = lower_bound(v.begin(),v.end(),(long long)(r/l)) - v.begin();
        if(v[a] == (long long)(r/l)){
            maxi = a+1;
            if((v[a]*3/2) <= (long long)(r/l)){
                c += maxi;
            }
            else{
                c++;
            }
            if((long long)(r/((v[a]*3/2))) >= l){
                c += (maxi-1)*((long long)(r/((v[a]*3/2))) - l);
            }
            c += ((long long)(r/v[a]) - l);
        }
        else{
            maxi = a;
            if((v[a-1]*3/2) <= (long long)(r/l)){
                c += maxi;
            }
            else{
                c++;
            }
            if((long long)(r/((v[a-1]*3/2))) >= l){
                c += (maxi-1)*((long long)(r/((v[a-1]*3/2))) - l);
            }
            c += ((long long)(r/v[a-1]) - l);
        }
        cout<<maxi<<" "<<c<<endl;
}