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
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{

    string s;

    cin>>s;

    long long n=(long long)s.length();

    long long l1=1;
    long long r1=n;

    for(long long i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            l1=i+1;
            break;
        }
    }
    long long count=0;

    for(long long i=l1-1;i<n;i++)
    {
        if(s[i]=='1')
        count++;
        else
        break;
        
    }
    long long size=n-count;
    if(size==0)
    {
        cout<<l1<<" "<<r1<<" "<<1<<" "<<1<<endl;
        return;
    }

    string s1=s.substr(l1-1,r1-l1+1);
    vector<long long>index(size,0);
    string s3=s.substr(l1-1+count);

    // debug(s1,s3,l1);
    long long l2=0;
    long long r2=0;
    for(long long i=0;(i+size)<n;i++)
    {
        string s2=s.substr(i,size);
        vector<long long>cindex(size,0);

        for(long long j=0;j<size;j++)
        {
            if(s3[j]!=s2[j])
            {
                cindex[j]=1;
            }
        }
        long long flag=0;
        for(long long j=0;j<size;j++)
        {
            if(index[j]==1 && cindex[j]==0)
            break;
            if(cindex[j]==1 && index[j]==0)
            flag=1;
            
        }

        if(flag)
        {
            index=cindex;
            l2=i+1;
            r2=i+size;
        }
    }


    cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;

}