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
    long long n,k,pb,ps;
    cin>>n>>k>>pb>>ps;

    long long p[n+1];

    long long arr[n+1];

    for(long long i=1;i<=n;i++)
    cin>>p[i];

    for(long long i=1;i<=n;i++)
    cin>>arr[i];
    

    long long currb=pb;

    long long resb=0;
    long long kb=k;
    long long sb=0;
    do{
        if(kb<=0)
        break;
        sb+=arr[currb];
        kb--;
        resb=max(resb,sb+kb*arr[currb]);
        currb=p[currb];
    }while(currb!=pb);


    long long currs=ps;
    long long ress=0;
    long long ks=k;
    long long ss=0;
    do{
        if(ks<=0)
        break;
        ss+=arr[currs];
        ks--;
        ress=max(ress,ss+ks*arr[currs]);
        currs=p[currs];
    }while(currs!=ps);

    if(resb>ress)
    {
        cout<<"Bodya"<<endl;
    }
    else if(ress>resb)
    {
        cout<<"Sasha"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
}