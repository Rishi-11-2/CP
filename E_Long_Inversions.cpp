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
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long res=1;
    vector<long long>nums(n,0);
    for(long long i=0;i<n;i++)
    {
        nums[i]=(s[i]-'0');
    }
    for(long long k=2;k<=n;k++)
    {
        long long flag=1;
        vector<long long> flips(n, 0);
        for(long long i = 0; i < n; i++){
            long long currBit = nums[i];
            if(i > 0){
                long long prev = flips[i - 1];
                long long beforeK = (i - k >= 0 ? flips[i - k] : 0);
                long long totalOps = prev - beforeK;
                if(totalOps % 2 != 0){
                    currBit = currBit ^ 1;
                    // flipped current bit due to previous operations
                }
            }
            if(currBit == 0){
                if(i + k > n){
                    flag=0;
                    break;
                }
                flips[i] = 1;
            }
            if(i > 0){
                flips[i] += flips[i - 1]; // prefix sum
            }
            // nums[i] = 1;
        }

        if(flag)
        res=k;
    }
    cout<<res<<endl;
}