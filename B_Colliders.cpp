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
        solve();
}
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int>spf(n+1,0);
    for(int i=1;i<=n;i++)
    {
        spf[i]=i;
    }

    for(int i=2;i<=n;i++)
    {
        if(spf[i]==i)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                spf[j]=i;
            }
        }
    }

    vector<int>activate(n+1,0);
    map<int,int>mp;
    vector<int>count(n+1,0);
    for(int j=1;j<=m;j++)
    {
        char operation;
        cin>>operation;
        if(operation=='+')
        {
            int x;
            cin>>x;
            // debug(spf[x]);
            if(activate[x])
            {
                cout<<"Already on"<<"\n";
                continue;
            }
            int y=x;
            int flag=0;
            int prev=-1;
            while(y!=1)
            {
                if(activate[spf[y]]||count[spf[y]])
                {
                    // debug(spf[y]);
                    cout<<"Conflict with "<<mp[spf[y]]<<endl;
                    flag=1;
                    break;
                }
                y=y/spf[y];
            }
            // debug("ho");
            if(flag)
            continue;
            // debug("ho");
            y=x;
            prev=-1;
            while(y!=1)
            {
                if(prev!=spf[y])
                {
                    prev=spf[y];
                    mp[spf[y]]=x;
                    // debug(mp[spf[y]],spf[y]);
                }
                count[spf[y]]++;
                y/=spf[y];
            }
            activate[x]=1;
            cout<<"Success"<<endl;

        }
        else
        {
            int x;
            cin>>x;
            if(!activate[x])
            {
                cout<<"Already off"<<endl;
                continue;
            }
            activate[x]=0;
            int y=x;
            while(y!=1)
            {
                count[spf[y]]--;
                y=y/spf[y];
            }
            cout<<"Success"<<endl;
        }
    }
}