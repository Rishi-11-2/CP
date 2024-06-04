#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long m,x;
    cin>>m>>x;

    vector<long long>c(m,0);

    for(long long i=0;i<m;i++)
    cin>>c[i];
    
    priority_queue<long long>pq;

    long long res=0;
    long long cm=x;
    long long sum=0;
    for(long long i=1;i<m;i++)
    {
        if(cm>=c[i])
        {
            pq.push(c[i]);
            cm-=c[i];
            sum++;
            res=max(res,sum);
        }
        else
        {
            while(!pq.empty() && pq.top()>c[i] && cm<c[i])
            {
                sum-=1;
                cm+=pq.top();
                pq.pop();
            }
            if(cm>=c[i])
            {
                sum+=1;
                cm-=c[i];
                pq.push(c[i]);
            }
        }
        cm+=x;
        res=max(res,sum);
    }
    cout<<res<<endl;
    
}