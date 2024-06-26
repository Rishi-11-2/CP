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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
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
    int n,mm;
    cin>>n>>mm;

    int m=(1<<n);

    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }

    int tree[4*m];

    function<int(int,int,int)>build=[&](int ss,int se,int si)->int{

        if(ss==se)
        {
            tree[si]=arr[se];
            return 1;
        }

        int mid=(ss+se)/2;
        int left=build(ss,mid,2*si+1);
        int right=build(mid+1,se,2*si+2);

        if(left%2)
        {
            tree[si]=(tree[2*si+1]|tree[2*si+2]);
        }
        else
        {
            tree[si]=(tree[2*si+1]^tree[2*si+2]);
        }

        return left+1;
    };

    int r=build(0,m-1,0);

    function<int(int,int,int,int,int)>update=[&](int ss,int se,int si,int pos,int val)->int{

        if(ss==se)
        {
            tree[si]=val;
            return 1;
        }

        int mid=(ss+se)/2;
        int rl=0;
        if(pos<=mid)
        rl=update(ss,mid,2*si+1,pos,val);
        else
        rl=update(mid+1,se,2*si+2,pos,val);

        if(rl%2)
        {
            tree[si]=(tree[2*si+1]|tree[2*si+2]);
        }
        else
        {
            tree[si]=(tree[2*si+1]^tree[2*si+2]);
        }

        return rl+1;
    };

    vector<int>res;
    for(int i=1;i<=mm;i++)
    {
        int p,b;
        cin>>p>>b;

        p--;
        arr[p]=b;

        int x=update(0,m-1,0,p,b);
        res.push_back(tree[0]);
    }

    for(auto it:res)
    cout<<it<<endl;
}