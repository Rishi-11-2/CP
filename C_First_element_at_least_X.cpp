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
    long long n,m;
    cin>>n>>m;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    long long tree[4*n];
    function<void(long long,long long,long long)>build=[&](long long ss,long long se,long long si)->void{

        if(ss==se)
        {
            tree[si]=arr[ss];
            return;
        }

        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=max(tree[2*si+1],tree[2*si+2]);
    };


    build(0,n-1,0);

    function<void(long long,long long,long long,long long,long long)>update=[&](long long ss,long long se,long long si,long long pos,long long val)->void{

        if(ss==se)
        {
            tree[si]=val;
            return;
        }


        long long mid=(ss+se)/2;

        if(pos<=mid)
        {
            update(ss,mid,2*si+1,pos,val);
        }
        else
        {
            update(mid+1,se,2*si+2,pos,val);
        }

        tree[si]=max(tree[2*si+1],tree[2*si+2]);

    };


    function<long long(long long,long long,long long,long long,long long)>query=[&](long long ss,long long se,long long si,long long l,long long r)->long long{

        if(se<l || ss>r)
        return 0;


        if(ss>=l && se<=r)
        {
            return tree[si];
        }


       long long mid=(ss+se)/2;

       return max(query(ss,mid,2*si+1,l,r),query(mid+1,se,2*si+2,l,r));
    };



    vector<long long>ans;
    for(long long i=1;i<=m;i++)
    {
        long long type;
        cin>>type;

        if(type==1)
        {
            long long idx,val;
            cin>>idx>>val;
            arr[idx]=val;
            update(0,n-1,0,idx,val);
        }
        else
        {
            long long x;
            cin>>x;
            long long res=-1;

            long long low=0;
            long long high=n-1;
            while(low<=high)
            {
                long long mid=(low+high)/2;
                long long y=query(0,n-1,0,low,mid);
                // debug(low,mid,high,y);
                if(y>=x)
                {
                    high=mid-1;
                    res=mid;
                }
                else if(y<x)
                {
                    low=mid+1;
                }

            }
            

            ans.push_back(res);
        }
    }


    for(auto it:ans)
    cout<<it<<endl;
}