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
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void make_query1(int n)
{
    cout<<"+ "<<n<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
}
int make_query2(int i,int j)
{
    cout<<"? " <<i<<" "<<j<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
void solve()
{
    int n;
    cin>>n;

    make_query1(n+1);
    make_query1(n+2);

    vector<int>dist1(n+1,0);
    vector<int>v(n+1,0);

    int count=1;
    for(int i=1;i<=n;i+=2)
    {
        v[i]=count;
        count++;
    }
    count=n;
    for(int i=2;i<=n;i+=2)
    {
        v[i]=count;
        count--;
    }
    for(int i=2;i<=n;i++)
    {
        dist1[i]=make_query2(1,i);
    }

    int maxm=0;
    int idx=-1;
    for(int i=1;i<=n;i++)
    {
        if(dist1[i]>maxm)
        {
            maxm=dist1[i];
            idx=i;
        }
    }

    int r1=v[maxm+1];
    int r2=v[n-maxm];

    vector<int>res1(n+1,0);
    vector<int>res2(n+1,0);
    res1[1]=r1;
    res2[1]=r2;
    res1[idx]=v[1];
    res2[idx]=v[n];

    vector<int>dist2(n+1,0);
    map<pair<int,int>,int>mp1;
    map<pair<int,int>,int>mp2;
    for(int i=2;i<=n;i++)
    {
        if(i==(idx))
        continue;

        dist2[i]=make_query2(idx,i);

    }
    for(int i=1;i<=n;i++)
    {
        mp1[{abs(i-(maxm+1)),abs(i-1)}]=v[i];
        mp2[{abs(i-(n-maxm)),abs(i-n)}]=v[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(i==(idx))
        continue;
        res1[i]=mp1[{dist1[i],dist2[i]}];
        res2[i]=mp2[{dist1[i],dist2[i]}];
    }

    cout<<"! ";
    for(int i=1;i<=n;i++)
    cout<<res1[i]<<" ";
    for(int i=1;i<=n;i++)
    cout<<res2[i]<<" ";
    cout<<endl;

    int x;
    cin>>x;
    if(x==-2)
    exit(0);
}