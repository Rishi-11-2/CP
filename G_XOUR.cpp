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
        long long n;
        cin>>n;

        long long arr[n];
        for(long long i=0;i<n;i++)
        cin>>arr[i];
        long long r=0;
        for(long long j=0;j<40;j++)
        {
            if(j>=2)
            {
                r=r|(1LL<<j);
            }
        }
        map<long long,vector<long long>>mp1;
        map<long long,vector<long long>>mp2;
        for(long long i=0;i<n;i++)
        {
            long long x=arr[i] & r;
            // debug(i,x);
            mp1[x].push_back(arr[i]);
            mp2[x].push_back(i);
        }
        vector<long long>res(n,0);
        for(auto it:mp1)
        {
            auto v1=it.second;
            sort(v1.begin(),v1.end());

            auto v2=mp2[it.first];
            sort(all(v2));
            long long sz=(long long)(v2.size());
            for(long long i=0;i<sz;i++)
            {
                // debug(it.first,v1[i],v2[i]);
                res[v2[i]]=v1[i];
            }
        }

        for(long long i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;



    }