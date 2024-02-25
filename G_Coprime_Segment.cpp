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
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    if(n==1)
    {
        if(arr[0]==1)
        cout<<1<<endl;
        else
        cout<<-1<<endl;
        return;
    }

    vector<stack<long long>>left(2);
    vector<stack<long long>>right(2);
    /* 0 -> for elements */
    /* 1-> for gcd  */
    long long i=0;
    long long j=0;
    long long res=INT_MAX;
    while(j<n)
    {
        right[0].push(arr[j]);
        if(right[1].size()>0)
        right[1].push(__gcd(arr[j],right[1].top()));
        else
        right[1].push(arr[j]);
        if(left[0].empty())
        {
            long long g=0;
            while(!right[0].empty())
            {
                left[0].push(right[0].top());
                g=__gcd(g,right[0].top());
                left[1].push(g);
                right[0].pop();
                right[1].pop();
            }
        }
        
        // cout <<i <<" "<<j <<endl;
        long long g1= right[0].size()>0 ? right[1].top():0;
        long long g2=left[0].size()>0 ? left[1].top():0;
        // cout << g1<< " bahar "<<g2<<endl;
        while(i<=j   && __gcd(g1,g2)==1)
        {
            res=min(res,j-i+1);
            i++;
            left[0].pop();
            left[1].pop();
            if(left[0].empty())
        {
            long long g=0;
            while(!right[0].empty())
            {
                left[0].push(right[0].top());
                g=__gcd(g,right[0].top());
                left[1].push(g);
                right[0].pop();
                right[1].pop();
            }
        }
             g1= right[0].size()>0 ? right[1].top():0;
         g2=left[0].size()>0 ? left[1].top():0;
         
        //  cout << g1<< " hello "<<g2<<endl;
        //  cout << i << "lesss "<<j<<endl;
        }

        j++;

    }
    if(res!=INT_MAX)
    cout<<res<<endl;
    else
    cout << -1 <<endl;
}