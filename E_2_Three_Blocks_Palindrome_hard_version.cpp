#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
void solve()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<vector<int>>prefix(n+1,vector<int>(201,0));
    for(int i=0;i<n;i++)
    {
        if(i)
        {
            prefix[i]=prefix[i-1];
        }
        prefix[i][arr[i]]++;
    }

    auto f=[&](int l,int r,int num,auto&& f)->int{

        int s=prefix[r][num];
        if(l)
        {
            s-=prefix[l-1][num];
        }

        return s;
    };

    vector<int>v(201,0);
    map<pair<int,int>,int>lpos;
    map<pair<int,int>,int>rpos;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
        v[arr[i]]++;
        lpos[{arr[i],v[arr[i]]}]=i;
    }
    v.assign(201,0);
    for(int i=n-1;i>=0;i--)
    {
        v[arr[i]]++;
        rpos[{arr[i],v[arr[i]]}]=i;
    }
    int ans=0;
    for(auto i:s)
    {
        ans=max(ans,v[i]);
        for(int j=1;j<=(v[i]/2);j++)
        {
            int l=lpos[{i,j}];
            int r=rpos[{i,j}];
            // debug(l,r,j);
            for(auto k:s)
            {
                if(k==i)
                continue;

                ans=max(ans,2*j+f(l,r,k,f));
            }
        }
    }
    cout<<ans<<endl;
}