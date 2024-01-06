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
        solve();
}
void solve()
{
    long long x1,y1;
    cin>>x1>>y1;
    long long x2,y2;
    cin>>x2>>y2;
    long long n;
    cin>>n;
    string s;
    cin>>s;
    map<char,long long>mp;
    mp['L']=-1;
    mp['R']=1;
    mp['U']=1;
    mp['D']=-1;

    vector<long long>prefixX(n,0);
    vector<long long>prefixY(n,0);
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='L'||s[i]=='R')
        {
            prefixX[i]=mp[s[i]];
        }
        if(s[i]=='U'||s[i]=='D')
        {
            prefixY[i]=mp[s[i]];
        }
        if(i-1>=0)
        {
            prefixX[i]+=prefixX[i-1];
            prefixY[i]+=prefixY[i-1];
        }
    }

    // for(long long i=0;i<n;i++)
    // cout<<prefixX[i]<<" ";
    // cout<<endl;
    // for(long long i=0;i<n;i++)
    // cout<<prefixY[i]<<" ";
    // cout<<endl;
    function<long long(long long)>f=[&](long long mid)->long long{
        long long totx=0;
        long long toty=0;
        long long d=mid/n;
        if(d>0)
        {
            totx+=d*prefixX[n-1];
            toty+=d*prefixY[n-1];
        }
        long long mod=mid%n;
        mod--;
        if(mod>=0)
        {
            totx+=prefixX[mod];
            toty+=prefixY[mod];
        }
        long long diffx=(x2-x1);
        long long diffy=(y2-y1);
        // debug(diffx,diffy,totx,toty);
        diffx-=totx;
        diffy-=toty;
        if(abs(diffx)+abs(diffy)<=mid)
        return 1;
        
        return 0;
    };
    long long low=0;
    long long high=(long long)(1e15);
    long long res=-1;
    // int x=f((int)(3));
    while(low<=high)
    {
        long long mid=(low+high)/2LL;
        if(f(mid))
        {
            res=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<res<<endl;
}