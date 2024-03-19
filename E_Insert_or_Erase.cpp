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
            solve();
    }
    void solve()
    {
        long long n;
        cin>>n;
        long long a[n];
        for(long long i=0;i<n;i++)
        cin>>a[i];
        
        long long q;
        cin>>q;

        map<long long,long long>prev;
        map<long long,long long>next;
        next[a[0]]=a[1];
        long long first=a[0];
        for(long long i=1;i<n-1;i++)
        {
            prev[a[i]]=a[i-1];
            next[a[i]]=a[i+1];
        }
        if(n>=2)
        prev[a[n-1]]=a[n-2];
        next[a[n-1]]=0;
        prev[a[0]]=0;
        for(long long i=1;i<=q;i++)
        {
            long long x;
            cin>>x;
            if(x==1)
            {
                long long c,d;
                cin>>c>>d;
                long long nn=next[c];
                next[c]=d;
                next[d]=nn;
                prev[d]=c;
                prev[nn]=d;
            }
            else
            {
                long long x;
                cin>>x;
                if(x==first)
                {
                    first=next[x];
                    prev[first]=-1;
                }
                else
                {
                    next[prev[x]]=next[x];
                    prev[next[x]]=prev[x];
                }
                next[x]=0;
                prev[x]=0;
            }
        }

        vector<long long>res;
        while(first!=0)
        {
            cout<<first<<" ";
            first=next[first];
        }
        cout<<endl;
    }