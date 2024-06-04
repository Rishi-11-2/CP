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
void solve()
{
    int n;
    cin>>n;

    int arr[n];

    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=-1)
        {
            v.push_back(i);
        }
    }

    int sz=(int)(v.size());
    if(sz==0)
    {
        int x=1;
        for(int i=0;i<n;i++)
        {
            cout<<x<<" ";
            x=x*2;
        }
        cout<<endl;
        return;
    }
    vector<int>res(n,-1);
    for(int k=1;k<sz;k++)
    {
        int a=v[k-1];
        int b=v[k];
        int diff=(b-a)-1;
        int i=a+1;
        int j=b-1;

        int a1=arr[v[k-1]];
        int a2=arr[v[k]];
        res[a]=a1;
        res[b]=a2;
        while(a2>0)
        {
            if(res[j]!=-1 && (res[j]!=(a2/2)) && ((res[j]/2)!=a2))
            {
                cout<<-1<<endl;
                return;
            }
            res[j]=a2/2;
            a2=a2/2;
            j--;
        }

        while(a1>0)
        {
            if(res[i]!=-1 && (res[i]!=(a1/2)) && ((res[i]/2)!=a1))
            {
                cout<<-1<<endl;
                return;
            }
            res[i]=a1/2;
            a1=a1/2;
            i++;
        }
        int len=j-i+1;
        if(len%2==0)
        {
            cout<<-1<<endl;
            return;
        }

        a1=2;
        while(i<=j)
        {
            res[i]=a1;
            if(a1==2)
            {
                a1=1;
            }
            else
            {
                a1=2;
            }
            i++;
        }

    }
    int x=arr[v[0]];
    for(int i=v[0]-1;i>=0;i--)
    {
        res[i]=x*2;
        x=x*2;
    }
    x=arr[v[sz-1]];
    for(int i=v[sz-1]+1;i<n;i++)
    {
        res[i]=x*2;
        x=x*2;
    }
    for(int i=0;i<n;i++)
    cout<<res[i]<<" ";
    cout<<endl;
}